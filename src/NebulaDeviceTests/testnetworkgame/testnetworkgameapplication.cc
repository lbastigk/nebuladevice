//------------------------------------------------------------------------------
//  testgameapplication.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "NebulaDeviceTests/testnetworkgame/testnetworkgameapplication.h"
#include "NebulaDeviceTests/testnetworkgame/testgamestate.h"
#include "NebulaDeviceTests/testnetworkgame/lobbygamestate.h"
#include "NebulaDeviceTests/testnetworkgame/testgamenotificationhandler.h"
#include "Nebuladevice/application/basegamefeature/statehandlers/gamestatehandler.h"
#include "Nebuladevice/application/basegamefeature/basegamefeatureunit.h"
#include "Nebuladevice/application/graphicsfeature/graphicsfeatureunit.h"
#include "Nebuladevice/render/debugrender/debugrender.h"

namespace Tools
{
using namespace Graphics;
using namespace Math;
using namespace Util;
using namespace Resources;
using namespace Timing;

__ImplementSingleton(TestNetworkGameApplication);   
//------------------------------------------------------------------------------
/**
*/
TestNetworkGameApplication::TestNetworkGameApplication()
{
    __ConstructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
TestNetworkGameApplication::~TestNetworkGameApplication()
{
    if (this->IsOpen())
    {
        this->Close();
    }
    __DestructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
void 
TestNetworkGameApplication::SetupStateHandlers()
{  
    // create our lobby gamestatehandler
    Ptr<Tools::LobbyGameState> lobbyState = Tools::LobbyGameState::Create();
    lobbyState->SetSetupMode(BaseGameFeature::GameStateHandler::NewGame);
    lobbyState->SetName("LobbyState");
    lobbyState->SetLevelName("testlevel");  
    this->AddStateHandler(lobbyState.get());

    // create our standard gamestatehandler
    Ptr<Tools::TestGameState> gameState = Tools::TestGameState::Create();
    gameState->SetSetupMode(BaseGameFeature::GameStateHandler::NewGame);
    gameState->SetName("GameState");
    // set level from session info
    gameState->SetLevelName("testlevel");    
    this->AddStateHandler(gameState.get());

    this->SetState("LobbyState");
}

//------------------------------------------------------------------------------
/**
*/
void
TestNetworkGameApplication::SetupGameFeatures()
{
    GameApplication::SetupGameFeatures();

    this->graphicsFeature = GraphicsFeature::GraphicsFeatureUnit::Create();
    this->gameServer->AttachGameFeature(this->graphicsFeature.upcast<Game::FeatureUnit>());
    this->baseGameFeature = BaseGameFeature::BaseGameFeatureUnit::Create();
    this->gameServer->AttachGameFeature(this->baseGameFeature.upcast<Game::FeatureUnit>());
    this->multiplayerFeature = MultiplayerFeature::MultiplayerFeatureUnit::Create();
    this->multiplayerFeature->SetNotificationHandlerRtti(&TestGameNotificationHandler::RTTI);
    this->gameServer->AttachGameFeature(this->multiplayerFeature.upcast<Game::FeatureUnit>());

#if __USE_PHYSICS__
    // create and attach core features
    this->physicsFeature = PhysicsFeature::PhysicsFeatureUnit::Create();    
    this->gameServer->AttachGameFeature(this->physicsFeature.upcast<Game::FeatureUnit>());
#endif	
}

//------------------------------------------------------------------------------
/**
    Cleanup all added game features
*/
void
TestNetworkGameApplication::CleanupGameFeatures()
{    
#if __USE_PHYSICS__
    this->gameServer->RemoveGameFeature(this->physicsFeature.upcast<Game::FeatureUnit>());
    this->physicsFeature = 0;
#endif
    this->gameServer->RemoveGameFeature(this->baseGameFeature.upcast<Game::FeatureUnit>());
    this->gameServer->RemoveGameFeature(this->graphicsFeature.upcast<Game::FeatureUnit>());
    this->gameServer->RemoveGameFeature(this->multiplayerFeature.upcast<Game::FeatureUnit>());

    this->baseGameFeature = 0;
    this->graphicsFeature = 0;
    this->multiplayerFeature = 0;

    GameApplication::CleanupGameFeatures();
}
} // namespace Tools
