#pragma once
//------------------------------------------------------------------------------
/**
    @class Test::Drasa3TestUiApplication        

    (C) 2010 Radon Labs GmbH
*/
#include "Nebuladevice/render/apprender/viewerapplication.h"
#include "Nebuladevice/render/graphics/spotlightentity.h"
#include "Nebuladevice/render/graphics/modelentity.h"
#include "Nebuladevice/render/graphics/globallightentity.h"
#include "Nebuladevice/render/graphics/pointlightentity.h"
#include "NebulaDeviceTests/drasa3testui/ui/mainscreen.h"
#include "Nebuladevice/addons/ui/uirenderer.h"
#include "Nebuladevice/addons/ui/uirendermodule.h"
#include "Nebuladevice/addons/ui/uimanager.h"

//------------------------------------------------------------------------------
namespace Test
{
class Drasa3TestUiApplication : public App::ViewerApplication
{
public:
    /// constructor
    Drasa3TestUiApplication();
    /// destructor
    virtual ~Drasa3TestUiApplication();
    /// open the application
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

    /// update the GUI
    void UpdateGUI();

    Ptr<Graphics::ModelEntity> ground;
    Util::Array<Ptr<Graphics::ModelEntity> > models;
    Ptr<Graphics::GlobalLightEntity> globalLight;
    Util::Array<Ptr<Graphics::PointLightEntity> > pointLights;
    Ptr<Graphics::SpotLightEntity> testSpotLight;
    Util::Array<Ptr<Graphics::SpotLightEntity> > spotLights;
    Util::Array<Math::matrix44> lightTransforms; 
    Math::float4 shadowConstants;
    float direction;
    Util::Array<Timing::Time> frameTimes;
    Timing::Time avgFPS;
    bool benchmarkmode;
    bool renderDebug;
    float rotX;

    // client side stuff
    Ptr<UI::UIManager> uiManager;
    Ptr<UI::UIRenderer> uiRenderer;
    // connection to render thread
    Ptr<UI::UIRenderModule> uiRenderModule;

    Ptr<UI::MainScreen> mainWindow;
};

} // namespace Test
//------------------------------------------------------------------------------
