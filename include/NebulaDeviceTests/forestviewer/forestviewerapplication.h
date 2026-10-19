#pragma once
//------------------------------------------------------------------------------
/**
    @class Tools::ForestViewer
    
    Nebula3 test viewer app.

    (C) 2006 Radon Labs GmbH
*/
#include "Nebuladevice/render/apprender/viewerapplication.h"
#include "Nebuladevice/render/graphics/spotlightentity.h"
#include "Nebuladevice/render/graphics/modelentity.h"
#include "Nebuladevice/render/graphics/globallightentity.h"
#include "Nebuladevice/render/graphics/pointlightentity.h"
#include "Nebuladevice/addons/forest/forestrendermodule.h"

//------------------------------------------------------------------------------
namespace Tools
{
class ForestViewerApplication : public App::ViewerApplication
{
public:
    /// constructor
    ForestViewerApplication();
    /// destructor
    virtual ~ForestViewerApplication();
    /// open the application
    virtual bool Open();
    /// close the application
    virtual void Close();

private:
    /// setup light sources
    void SetupLights();
    /// removes light sources
    void DestroyLights();
    /// setup models
    void SetupGeometry();
    /// removes all models
    void DestroyGeometry();
    /// process input (called before rendering)
    virtual void OnProcessInput();
    /// render current frame
    virtual void OnUpdateFrame();
    /// called to configure display
    virtual void OnConfigureDisplay();

    Ptr<Graphics::ModelEntity> ground;
    Util::Array<Ptr<Graphics::ModelEntity> > models;
    Ptr<Graphics::GlobalLightEntity> globalLight;
    Util::Array<Timing::Time> frameTimes;
    Ptr<Forest::ForestRenderModule> forestModule;
    Timing::Time avgFPS;
    bool benchmarkmode;
    bool renderDebug;
    float rotX;
};

} // namespace Test
//------------------------------------------------------------------------------
