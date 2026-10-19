#pragma once
//------------------------------------------------------------------------------
/**
    @class Debug::ForestHandler
    
    Handles debug-visualization messages in the graphics thread.
    
    (C) 2008 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/interface/interfacehandlerbase.h"
#include "Nebuladevice/foundation/messaging/message.h"
#include "Nebuladevice/addons/forest/forestprotocol.h"


//------------------------------------------------------------------------------
namespace Forest
{
class ForestHandler : public Interface::InterfaceHandlerBase
{
    __DeclareClass(ForestHandler);
public:
    /// constructor
    ForestHandler();
    /// destructor
    virtual ~ForestHandler();  

    /// handle a message, return true if handled
    virtual bool HandleMessage(const Ptr<Messaging::Message>& msg);

private:
    /// On setup 
    void OnLoadLevel(const Ptr<Forest::LoadLevel>& msg);
    /// On exit level
    void OnExitLevel();
    /// On create tree instance
    void OnCreateTreeInstance(const Ptr<Forest::CreateTreeInstance>& msg);
    /// On setup collide mesh
    void OnSetupCollideMesh();

};

} // namespace Forest
//------------------------------------------------------------------------------