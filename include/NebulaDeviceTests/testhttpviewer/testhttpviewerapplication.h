#pragma once
//------------------------------------------------------------------------------
/**
    @class Tools::TestHttpViewerApplication
    
    Nebula3 test viewer app.

    (C) 2006 Radon Labs GmbH
*/
#include "Nebuladevice/render/apprender/viewerapplication.h"
#include "Nebuladevice/render/graphics/spotlightentity.h"
#include "Nebuladevice/render/graphics/modelentity.h"
#include "Nebuladevice/render/graphics/globallightentity.h"
#include "Nebuladevice/render/graphics/pointlightentity.h"

//------------------------------------------------------------------------------
namespace Tools
{
class TestHttpViewerApplication : public App::ViewerApplication
{
public:
    /// constructor
    TestHttpViewerApplication();
    /// destructor
    virtual ~TestHttpViewerApplication();
    // open the application
    virtual bool Open();
    /// close the application
    virtual void Close();

private:
    /// process input (called before rendering)
    virtual void OnProcessInput();
    /// render current frame
    virtual void OnUpdateFrame();
    /// called to configure display
    virtual void OnConfigureDisplay();

    Ptr<Graphics::ModelEntity> ground;
    Util::Array<Ptr<Graphics::ModelEntity> > models;
    Ptr<Graphics::GlobalLightEntity> globalLight;
    Util::Array<Ptr<Graphics::PointLightEntity> > localLights;
    Util::Array<Math::matrix44> lightTransforms; 
    Util::Array<Timing::Time> frameTimes;
    Timing::Time avgFPS;
    bool benchmarkmode;
    bool renderDebug;
};

} // namespace Test
//------------------------------------------------------------------------------
