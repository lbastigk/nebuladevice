#pragma once
//------------------------------------------------------------------------------
/**
    @class Tools::TestGameApplication
    
    Nebula3 Application layer test app.

    (C) 2006 Radon Labs GmbH
*/
#include "Nebuladevice/application/appgame/gameapplication.h"
#include "Nebuladevice/application/basegamefeature/basegamefeatureunit.h"
#include "Nebuladevice/foundation/framesync/framesynctimer.h"
#include "Nebuladevice/application/graphicsfeature/graphicsfeatureunit.h"

#if __USE_PHYSICS__
#include "Nebuladevice/application/physicsfeature/physicsfeatureunit.h"
#include "Nebuladevice/application/stateobjectfeature/stateobjectfeatureunit.h"
#endif

#if __USE_SCALEFORM__
#include "scaleform/scaleformfeatureunit.h"
#endif

//------------------------------------------------------------------------------
namespace Tools
{
class TestGameApplication : public App::GameApplication
{
    __DeclareSingleton(TestGameApplication);   
public:
    /// constructor
    TestGameApplication();
    /// destructor
    virtual ~TestGameApplication();
    
    /// open the application
    virtual bool Open();

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
};

} // namespace Test
//------------------------------------------------------------------------------