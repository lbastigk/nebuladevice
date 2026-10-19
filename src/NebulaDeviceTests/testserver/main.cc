//------------------------------------------------------------------------------
//  testserver.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "NebulaDeviceTests/testserver/testserverapplication.h"
#include "Nebuladevice/foundation/core/sysfunc.h"
#include <atomic>
#include <thread>

namespace
{
const ushort TestServerPort = 2352;

bool SendAll(SOCKET socket, const char* data, int size)
{
    int sent = 0;
    while (sent < size)
    {
        int result = send(socket, data + sent, size - sent, 0);
        if (result == SOCKET_ERROR || result == 0)
        {
            return false;
        }
        sent += result;
    }
    return true;
}

bool ReceiveAll(SOCKET socket, char* data, int size)
{
    int received = 0;
    while (received < size)
    {
        int result = recv(socket, data + received, size - received, 0);
        if (result == SOCKET_ERROR || result == 0)
        {
            return false;
        }
        received += result;
    }
    return true;
}

class ClientState
{
public:
    ClientState() : succeeded(false), serverClosed(false) {}

    void Run()
    {
        SOCKET socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (socket == INVALID_SOCKET)
        {
            return;
        }

        sockaddr_in address = {};
        address.sin_family = AF_INET;
        address.sin_port = htons(TestServerPort);
        address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

        bool connected = false;
        for (int attempt = 0; attempt < 20 && !connected; ++attempt)
        {
            connected = (connect(socket, (sockaddr*)&address, sizeof(address)) == 0);
            if (!connected)
            {
                n_sleep(0.1);
            }
        }
        if (!connected)
        {
            closesocket(socket);
            return;
        }

        const char* messages[] = {"hello", "shutdown"};
        for (int messageIndex = 0; messageIndex < 2; ++messageIndex)
        {
            const char* message = messages[messageIndex];
            ushort length = htons((ushort)strlen(message));
            char packet[32];
            memcpy(packet, &length, sizeof(length));
            memcpy(packet + sizeof(length), message, strlen(message));
            char response[32];
            ushort responseLength;
            if (!SendAll(socket, packet, sizeof(length) + strlen(message)) ||
                !ReceiveAll(socket, (char*)&responseLength, sizeof(responseLength)))
            {
                closesocket(socket);
                return;
            }

            responseLength = ntohs(responseLength);
            if (responseLength >= sizeof(response) ||
                !ReceiveAll(socket, response, responseLength) ||
                responseLength != strlen(message) ||
                0 != memcmp(response, message, responseLength))
            {
                closesocket(socket);
                return;
            }
        }

        while (!this->serverClosed.load())
        {
            std::this_thread::yield();
        }
        closesocket(socket);
        this->succeeded.store(true);
    }

    std::atomic<bool> succeeded;
    std::atomic<bool> serverClosed;
};
}

int main()
{
    Core::SysFunc::Setup();

    Tools::TestServerApplication server;
    server.SetCompanyName("Radon Labs GmbH");
    server.SetAppTitle("Test Server");
    if (!server.Open())
    {
        return 1;
    }

    ClientState clientState;
    std::thread client(&ClientState::Run, &clientState);

    server.Run();
    server.Close();
    clientState.serverClosed.store(true);
    client.join();
    return clientState.succeeded.load() ? 0 : 1;
}
