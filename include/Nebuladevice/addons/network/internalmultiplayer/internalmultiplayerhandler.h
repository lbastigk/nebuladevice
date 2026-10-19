#pragma once
//------------------------------------------------------------------------------
/**
    @class InternalMultiplayer::InternalMultiplayerHandler
    
    Runs in the InternalMultiplayer thread context, setup the InternalMultiplayerServer
    and processes messages to the InternalMultiplayer thread.
    The messages are handled by the Platform-specific InternalMultiplayerServer.

    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/interface/interfacehandlerbase.h"
#include "Nebuladevice/foundation/messaging/message.h"
#include "Nebuladevice/foundation/framesync/framesynctimer.h"
#include "Nebuladevice/foundation/threading/safeflag.h"
#include "Nebuladevice/foundation/threading/event.h"
#include "Nebuladevice/addons/network/internalmultiplayer/internalmultiplayerserver.h"         
#include "Nebuladevice/foundation/http/httpserverproxy.h"

//------------------------------------------------------------------------------
namespace InternalMultiplayer
{
class InternalMultiplayerHandler : public Interface::InterfaceHandlerBase
{
    __DeclareClass(InternalMultiplayerHandler);
public:
    /// constructor
    InternalMultiplayerHandler();
    /// destructor
    virtual ~InternalMultiplayerHandler();

    /// open the handler
    virtual void Open();
    /// close the handler
    virtual void Close();
    /// handle a message, return true if handled
    virtual bool HandleMessage(const Ptr<Messaging::Message>& msg);
    /// do per-frame work
    virtual void DoWork();

private:
    bool isInternalMultiplayerRuntimeValid;
    Ptr<FrameSync::FrameSyncTimer> frameSyncTimer;
    Ptr<InternalMultiplayerServer> internalMultiplayerServer;
#if __NEBULA3_HTTP__
    Ptr<Http::HttpServerProxy> httpServerProxy;
#endif
};
} // namespace InternalMultiplayerHandler
//------------------------------------------------------------------------------

