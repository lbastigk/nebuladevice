#pragma once
//------------------------------------------------------------------------------
/**
    @class Debug::DebugHandler
    
    The message handler for the debug interface. Just wakes up from time
    to time to check for incoming Http requests.
    
    (C) 2008 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/interface/interfacehandlerbase.h"
#include "Nebuladevice/foundation/io/console.h"
#include "Nebuladevice/foundation/debug/debugserver.h"
#include "Nebuladevice/foundation/http/httpserverproxy.h"

//---------
namespace Debug
{
class DebugHandler : public Interface::InterfaceHandlerBase
{
    __DeclareClass(DebugHandler);
public:
    /// constructor
    DebugHandler();
    /// destructor
    virtual ~DebugHandler();
    
    /// open the handler
    virtual void Open();
    /// close the handler
    virtual void Close();
    /// do per-frame work
    virtual void DoWork();

private:
    Ptr<DebugServer> debugServer;
    Ptr<Http::HttpServerProxy> httpServerProxy;
};

} // namespace Debug
//------------------------------------------------------------------------------
    