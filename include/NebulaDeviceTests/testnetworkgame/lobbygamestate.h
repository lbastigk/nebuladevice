#pragma once
//------------------------------------------------------------------------------
/**
    @class Tools::LobbyGameState

        
    (C) 2009 RadonLabs GmbH
*/
#include "Nebuladevice/application/basegamefeature/statehandlers/gamestatehandler.h"
#include "Nebuladevice/foundation/timing/time.h"
#include "Nebuladevice/foundation/math/point.h"
#include "Nebuladevice/foundation/util/dictionary.h"
#include "Nebuladevice/foundation/util/stringatom.h"

//------------------------------------------------------------------------------
namespace Tools
{
class LobbyGameState : public BaseGameFeature::GameStateHandler
{
    __DeclareClass(LobbyGameState);
public:    
    /// constructor
    LobbyGameState();
    /// destructor
    virtual ~LobbyGameState();

    /// called when the state represented by this state handler is entered
    virtual void OnStateEnter(const Util::String& prevState);
    /// called when the state represented by this state handler is left
    virtual void OnStateLeave(const Util::String& nextState);   
    /// called each frame as long as state is current, return new state
    virtual Util::String OnFrame();

private:
    /// handle different stages
    void HandleLogin(); 
    /// handle different stages
    void HandleIdle();     
    /// handle different stages
    void HandleHostingSession();    
    /// handle different stages
    void HandleGameSearch();    
    /// handle different stages
    void HandleClientGameLobby();
    /// handle different stages
    void HandleClientRunningGame();
    /// handle different stages
    void HandleHostRunningGame();
    /// handle a test data package send
    void HandleTestDataPackage();

    /// show menu entry
    void RenderMenuEntry(const Util::String& button, const Util::String& desc);
    /// test if button action is pressed
    bool IsBtnAction(const Util::String& button);

    bool startingHosting;
    SizeT numMenuEntries;
    bool autoHost;
    bool autoClient;
    Util::Dictionary<Util::StringAtom, Math::point> btnColors;
};
};
//------------------------------------------------------------------------------