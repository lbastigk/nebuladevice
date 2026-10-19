#pragma once
#ifndef TOOLS_TESTGAMEAPPLICATION_H
#define TOOLS_TESTGAMEAPPLICATION_H
//------------------------------------------------------------------------------
/**
    @class Tools::TestNetGameApplication
    
    Nebula3 Application layer test app.

    (C) 2006 Radon Labs GmbH
*/
#include "Nebuladevice/application/appgame/gameapplication.h"
#include "Nebuladevice/application/basegamefeature/basegamefeatureunit.h"
#include "Nebuladevice/application/graphicsfeature/graphicsfeatureunit.h"
#include "Nebuladevice/application/stateobjectfeature/stateobjectfeatureunit.h"
#include "Nebuladevice/addons/network/multiplayerfeature/multiplayerfeatureunit.h"

#if __USE_PHYSICS__
#include "Nebuladevice/application/physicsfeature/physicsfeatureunit.h"
#endif

//------------------------------------------------------------------------------
namespace Tools
{
class TestNetworkGameApplication : public App::GameApplication
{
    __DeclareSingleton(TestNetworkGameApplication);   
public:
    /// constructor
    TestNetworkGameApplication();
    /// destructor
    virtual ~TestNetworkGameApplication();
    
protected:
    /// setup application state handlers
    virtual void SetupStateHandlers();
    /// setup game features
    virtual void SetupGameFeatures();
    /// cleanup game features
    virtual void CleanupGameFeatures(); 

private:
#if __USE_PHYSICS__
    Ptr<PhysicsFeature::PhysicsFeatureUnit> physicsFeature;
#endif    
    Ptr<GraphicsFeature::GraphicsFeatureUnit> graphicsFeature;
    Ptr<BaseGameFeature::BaseGameFeatureUnit> baseGameFeature;
    Ptr<MultiplayerFeature::MultiplayerFeatureUnit> multiplayerFeature;
};

} // namespace Test
//------------------------------------------------------------------------------
#endif
