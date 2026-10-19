#pragma once
//------------------------------------------------------------------------------
/**
    @class Game::BaseGameFeatureUnit
    
    The BaseGameFeatureUnit creates everything to allow load and run a game level.
    Therefore it creates managers to allow creation and handling of
    entities and its properties. It supports loading of a game level from a database
    with the db server and offers simple methods for opening a new game, loading a level 
    or a savegame.
    The Feature also creates the timemanager and different timesources used by subsystems.

    If you wanna use your own managers (other specilized entitymanager), derive from this class 
    and overwrite OnActivate() OnDeactivate().

    (C) 2007 Radon Labs GmbH
*/
#include "Nebuladevice/application/game/featureunit.h"
#include "Nebuladevice/foundation/math/bbox.h"
#include "Nebuladevice/application/basegamefeature/basegametiming/timemanager.h"
#include "Nebuladevice/application/basegamefeature/managers/factorymanager.h"
#include "Nebuladevice/application/basegamefeature/managers/focusmanager.h"
#include "Nebuladevice/application/basegamefeature/managers/entitymanager.h"
#include "Nebuladevice/application/basegamefeature/managers/categorymanager.h"
#include "Nebuladevice/application/basegamefeature/managers/globalattrsmanager.h"
#include "Nebuladevice/application/basegamefeature/managers/animeventmanager.h"
#include "Nebuladevice/addons/db/dbserver.h"
#include "Nebuladevice/application/basegamefeature/loader/loaderserver.h"
#include "Nebuladevice/application/basegamefeature/managers/enventitymanager.h"
#include "Nebuladevice/foundation/http/httprequesthandler.h"
#include "Nebuladevice/addons/vibration/vibrationinterface.h"
#include "Nebuladevice/addons/audio2/audio2server.h"
#include "Nebuladevice/addons/audio2/audio2interface.h"
#include "Nebuladevice/addons/audio2/audio2player.h"
#include "Nebuladevice/foundation/debug/debugcounter.h"

#if __USE_PHYSICS__
#include "Nebuladevice/application/basegamefeature/managers/envquerymanager.h"
#endif

//------------------------------------------------------------------------------
namespace BaseGameFeature
{

class BaseGameFeatureUnit : public Game::FeatureUnit    
{
    __DeclareClass(BaseGameFeatureUnit);
    __DeclareSingleton(BaseGameFeatureUnit);    

public:

    /// constructor
    BaseGameFeatureUnit();
    /// destructor
    virtual ~BaseGameFeatureUnit();

    /// called from BaseGameFeatureUnit::ActivateProperties()
    virtual void OnActivate();
    /// called from BaseGameFeatureUnit::DeactivateProperties()
    virtual void OnDeactivate();
         
    /// called at the end of the feature trigger cycle
    virtual void OnEndFrame();
    /// called when game debug visualization is on
    virtual void OnRenderDebug();
    /// 
    virtual void OnFrame();

    /// return true if a current game exists
    static bool CurrentGameExists();
    /// setup a new game
    virtual bool NewGame();
    /// continue game 
    virtual bool ContinueGame();
    /// create a new save game
    virtual bool SaveGame(const Util::String& saveGameName);
    /// load an existing save game
    virtual bool LoadGame(const Util::String& saveGameName);
    /// load an level from current db
    virtual bool LoadLevel(const Util::String& levelName);
    /// get name of startup level (defined in world database)
    Util::String GetStartupLevel();
    /// has level parameter set
    bool HasLevelParameter() const;

    /// set current level name
    void SetCurrentLevel(const Util::String& n);
    /// get current level name
    Util::String GetCurrentLevel() const;
    /// set optional world dimensions
    void SetWorldDimensions(const Math::bbox& box);
    /// get world dimensions
    const Math::bbox& GetWorldDimensions() const;
    /// setup an empty game world
    virtual void SetupEmptyWorld();
    /// setup world from level
    virtual void SetupWorldFromCurrentLevel();
    /// cleanup the game world
    virtual void CleanupWorld();

    /// set factory manager rtti
    void SetFactoryManager(const Ptr<FactoryManager>& manager);
        
protected:

    /// handle input keys
    void HandleInput();

    Ptr<FactoryManager> factoryManager;
    Ptr<FocusManager> focusManager;
    Ptr<EntityManager> entityManager;
    Ptr<GlobalAttrsManager> globalAttrManager;
    Ptr<CategoryManager> categoryManager;
    Ptr<TimeManager> timeManager;
    Ptr<BaseGameFeature::LoaderServer> loaderServer;
    Ptr<Db::DbServer> dbServer;
    Ptr<EnvEntityManager> envEntityManager;
    Ptr<AnimEventManager> animEventManager;
    Ptr<Audio2::Audio2Server> audioServer;
    Ptr<Audio2::Audio2Interface> audioInterface;
    Ptr<Audio2::Audio2Player> audioPlayer;    
    Ptr<Vibration::VibrationInterface> vibInterface;

#if __USE_PHYSICS__
    Ptr<EnvQueryManager> envQueryManager;
#endif    

#if __NEBULA3_HTTP__
    Ptr<Http::HttpRequestHandler> debugRequestHandler;
#endif

    Math::bbox worldBox;
	// debug counters/timers for perf-hud
	Ptr<Debug::DebugCounter> numPrimitives;
	Ptr<Debug::DebugCounter> numDrawCalls;
};

//------------------------------------------------------------------------------
/**
*/
inline void
BaseGameFeatureUnit::SetWorldDimensions(const Math::bbox& box)
{
    this->worldBox = box;
}

//------------------------------------------------------------------------------
/**
*/
inline const Math::bbox&
BaseGameFeatureUnit::GetWorldDimensions() const
{
    return this->worldBox;
}

//------------------------------------------------------------------------------
/**
*/
inline void 
BaseGameFeatureUnit::SetFactoryManager(const Ptr<FactoryManager>& manager)
{
    this->factoryManager = manager;
}

//------------------------------------------------------------------------------
/**
*/
inline bool 
BaseGameFeatureUnit::HasLevelParameter() const
{
    return this->args.HasArg("-level");
}

} // namespace BaseGameFeature
//------------------------------------------------------------------------------
