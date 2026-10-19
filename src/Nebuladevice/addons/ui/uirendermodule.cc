//------------------------------------------------------------------------------
//  uirendermodule.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/addons/ui/uirendermodule.h"
#include "Nebuladevice/addons/ui/rt/coreuirtplugin.h"
#include "Nebuladevice/addons/ui/uimanager.h"
#include "Nebuladevice/addons/ui/uirenderer.h"
#include "Nebuladevice/render/graphics/graphicsinterface.h"
#include "Nebuladevice/render/graphics/graphicsprotocol.h"

namespace UI
{
__ImplementClass(UI::UIRenderModule, 'UIRM', RenderModules::RenderModule);
__ImplementSingleton(UI::UIRenderModule);

using namespace RenderModules;
using namespace Graphics;
using namespace Messaging;
using namespace Util;

//------------------------------------------------------------------------------
/**
*/
UIRenderModule::UIRenderModule()
{
    __ConstructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
UIRenderModule::~UIRenderModule()
{
    __DestructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
void
UIRenderModule::Setup()
{
    n_assert(!this->IsValid());
    RenderModule::Setup();

    // setup UIRenderer and UIManager
    this->uiRenderer = UIRenderer::Create();
    this->uiRenderer->Setup();
    this->uiManager = UIManager::Create();
    this->uiManager->Open();

    // register the render-thread plugin
    Ptr<RegisterRTPlugin> msg = RegisterRTPlugin::Create();
    msg->SetType(&CoreUI::CoreUIRTPlugin::RTTI);
    GraphicsInterface::Instance()->Send(msg.cast<Message>());
}

//------------------------------------------------------------------------------
/**
*/
void
UIRenderModule::Discard()
{
    n_assert(this->IsValid());
    RenderModule::Discard();

    // unregister the render-thread plugin
    Ptr<UnregisterRTPlugin> msg = UnregisterRTPlugin::Create();
    msg->SetType(&CoreUI::CoreUIRTPlugin::RTTI);
    GraphicsInterface::Instance()->Send(msg.cast<Message>());

    // discard UIRenderer and UIManager
    this->uiManager->Close();
    this->uiManager = 0;
    this->uiRenderer->Discard();
    this->uiRenderer = 0;
}
} // namespace UI