//------------------------------------------------------------------------------
//  httpclienttest.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "NebulaDeviceTests/testfoundation/httpclienttest.h"
#include "Nebuladevice/foundation/http/httpclient.h"
#include "Nebuladevice/foundation/io/memorystream.h"
#include <atomic>
#include <string>
#include <thread>

namespace Test
{
__ImplementClass(Test::HttpClientTest, 'htct', Test::TestCase);

using namespace Util;
using namespace IO;
using namespace Http;

namespace
{
const ushort TestHttpPort = 2101;
const char* FixtureContent = "NebulaDevice HTTP fixture";

std::string BuildResponse(const std::string& path)
{
    std::string body;
    std::string status = "200 OK";
    if (path == "/fixture")
    {
        body = FixtureContent;
    }
    else if (path == "/fixture/large")
    {
        body.reserve(131072);
        for (IndexT i = 0; i < 8192; i++)
        {
            body.append("0123456789abcdef");
        }
    }
    else if (path == "/fixture/empty")
    {
        body.clear();
    }
    else
    {
        status = "404 Not Found";
        body = "404 Not Found";
    }

    char header[256];
    sprintf(
        header,
        "HTTP/1.1 %s\r\nContent-Length: %d\r\n"
        "Content-Type: text/plain\r\nConnection: close\r\n\r\n",
        status.c_str(),
        static_cast<int>(body.size()));
    return std::string(header) + body;
}

void RunFixtureServer(std::atomic<bool>& ready, std::atomic<bool>& failed)
{
    SOCKET listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (INVALID_SOCKET == listenSocket)
    {
        failed = true;
        return;
    }

    sockaddr_in address = {};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    address.sin_port = htons(TestHttpPort);
    if (SOCKET_ERROR == bind(
            listenSocket,
            reinterpret_cast<const sockaddr*>(&address),
            sizeof(address))
        || SOCKET_ERROR == listen(listenSocket, SOMAXCONN))
    {
        closesocket(listenSocket);
        failed = true;
        return;
    }

    ready = true;
    for (IndexT requestIndex = 0; requestIndex < 4; requestIndex++)
    {
        SOCKET clientSocket = accept(listenSocket, 0, 0);
        if (INVALID_SOCKET == clientSocket)
        {
            failed = true;
            break;
        }

        char request[4096];
        int requestSize = recv(clientSocket, request, sizeof(request) - 1, 0);
        if (requestSize <= 0)
        {
            closesocket(clientSocket);
            failed = true;
            break;
        }
        request[requestSize] = '\0';

        const char* pathStart = strstr(request, "GET ");
        const char* pathEnd = pathStart ? strchr(pathStart + 4, ' ') : 0;
        if (!pathStart || !pathEnd)
        {
            closesocket(clientSocket);
            failed = true;
            break;
        }
        std::string response = BuildResponse(
            std::string(pathStart + 4, pathEnd));
        SizeT bytesSent = 0;
        while (bytesSent < response.size())
        {
            int sent = send(
                clientSocket,
                response.data() + bytesSent,
                static_cast<int>(response.size() - bytesSent),
                0);
            if (sent <= 0)
            {
                failed = true;
                break;
            }
            bytesSent += sent;
        }
        closesocket(clientSocket);
        if (failed)
        {
            break;
        }
    }
    closesocket(listenSocket);
}
}

//------------------------------------------------------------------------------
/**
*/
void
HttpClientTest::Run()
{
    std::atomic<bool> serverReady(false);
    std::atomic<bool> serverFailed(false);
    std::thread serverThread(
        RunFixtureServer,
        std::ref(serverReady),
        std::ref(serverFailed));
    while (!serverReady && !serverFailed)
    {
        std::this_thread::yield();
    }
    this->Verify(!serverFailed);

    URI serverUri("http://127.0.0.1:2101");
    URI fixtureUri("http://127.0.0.1:2101/fixture");
    URI largeUri("http://127.0.0.1:2101/fixture/large");
    URI emptyUri("http://127.0.0.1:2101/fixture/empty");
    URI missingUri("http://127.0.0.1:2101/missing");

    Ptr<HttpClient> httpClient = HttpClient::Create();
    bool connected = httpClient->Connect(serverUri);
    this->Verify(connected);
    this->Verify(httpClient->IsConnected());

    Ptr<Stream> contentStream = MemoryStream::Create();
    HttpStatus::Code status = httpClient->SendRequest(
        HttpMethod::Get, fixtureUri, contentStream);
    this->Verify(HttpStatus::OK == status);
    this->Verify(contentStream->GetSize() == strlen(FixtureContent));
    contentStream->SetAccessMode(Stream::ReadAccess);
    contentStream->Open();
    char content[64];
    SizeT bytesRead = contentStream->Read(content, sizeof(content) - 1);
    content[bytesRead] = '\0';
    this->Verify(String(content) == FixtureContent);
    contentStream->Close();
    httpClient->Disconnect();
    this->Verify(!httpClient->IsConnected());

    httpClient = HttpClient::Create();
    this->Verify(httpClient->Connect(serverUri));
    contentStream = MemoryStream::Create();
    status = httpClient->SendRequest(HttpMethod::Get, largeUri, contentStream);
    this->Verify(HttpStatus::OK == status);
    this->Verify(contentStream->GetSize() == 131072);
    httpClient->Disconnect();

    httpClient = HttpClient::Create();
    this->Verify(httpClient->Connect(serverUri));
    contentStream = MemoryStream::Create();
    status = httpClient->SendRequest(HttpMethod::Get, emptyUri, contentStream);
    this->Verify(HttpStatus::OK == status);
    this->Verify(contentStream->GetSize() == 0);
    httpClient->Disconnect();

    httpClient = HttpClient::Create();
    this->Verify(httpClient->Connect(serverUri));
    contentStream = MemoryStream::Create();
    status = httpClient->SendRequest(HttpMethod::Get, missingUri, contentStream);
    this->Verify(HttpStatus::NotFound == status);
    httpClient->Disconnect();

    serverThread.join();
    this->Verify(!serverFailed);
}

} // namespace Test