#pragma once
//------------------------------------------------------------------------------
/**
    @class Tools::TestGameState

        
    (C) 2009 RadonLabs GmbH
*/
#include "Nebuladevice/application/basegamefeature/statehandlers/gamestatehandler.h"
#include "Nebuladevice/application/game/entity.h"
#include "Nebuladevice/foundation/timing/time.h"
#include "Nebuladevice/foundation/math/point.h"
#include "Nebuladevice/foundation/util/dictionary.h"
#include "Nebuladevice/foundation/util/stringatom.h"
#include "Nebuladevice/addons/network/multiplayer/player.h"

//------------------------------------------------------------------------------
namespace Tools
{
class TestGameState : public BaseGameFeature::GameStateHandler
{
    __DeclareClass(TestGameState);
public:    
    /// constructor
    TestGameState();
    /// destructor
    virtual ~TestGameState();

    /// called each frame as long as state is current, return new state
    virtual Util::String OnFrame();          
    /// called after Db is opened, and before entities are loaded
    virtual void OnLoadBefore();
    /// called after entities are loaded
    virtual void OnLoadAfter();                                       
    /// spawn player entity for joined player
    void SpawnPlayerEntity(const Ptr<Multiplayer::Player>& player);   
    /// remove player entity
    void RemovePlayerEntity(const Ptr<Multiplayer::Player>& player);

    /// only on host
    void SpawnPlayerEntities();
private:

    Util::Dictionary<Ptr<Multiplayer::Player>, Ptr<Game::Entity>> playerEntities;
};
};
//------------------------------------------------------------------------------