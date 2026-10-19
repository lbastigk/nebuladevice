#pragma once
//------------------------------------------------------------------------------
/**
    @class App::ViewerApplication
    
    Derived from RenderApplication, adds support for Stages, Views
    and GraphicsEntities to the asynchronous render app.
    
    (C) 2007 Radon Labs GmbH
*/
#include "Nebuladevice/render/apprender/renderapplication.h"
#include "Nebuladevice/render/graphics/graphicsserver.h"
#include "Nebuladevice/render/graphics/stage.h"
#include "Nebuladevice/render/graphics/view.h"
#include "Nebuladevice/render/graphics/cameraentity.h"
#include "Nebuladevice/render/renderutil/mayacamerautil.h"
#include "Nebuladevice/render/debugrender/debugshaperenderer.h"
#include "Nebuladevice/render/debugrender/debugtextrenderer.h"

//------------------------------------------------------------------------------
namespace App
{
class ViewerApplication : public RenderApplication
{
public:
    /// constructor
    ViewerApplication();
    /// destructor
    virtual ~ViewerApplication();
    /// open the application
    virtual bool Open();
    /// close the application
    virtual void Close();

protected:    
    /// process input (called before rendering)
    virtual void OnProcessInput();
    /// update world 
    virtual void OnUpdateFrame();

    Ptr<Graphics::GraphicsServer> graphicsServer;
    Ptr<Debug::DebugShapeRenderer> debugShapeRenderer;
    Ptr<Debug::DebugTextRenderer> debugTextRenderer;
    Ptr<Graphics::Stage> stage;
    Ptr<Graphics::View> view;
    Ptr<Graphics::CameraEntity> camera;
    RenderUtil::MayaCameraUtil mayaCameraUtil;
};

} // namespace Graphics
//------------------------------------------------------------------------------

    