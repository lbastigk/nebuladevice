//------------------------------------------------------------------------------
//  internalcameraentityhandler.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/graphics/graphicsprotocol.h"
#include "Nebuladevice/render/internalgraphics/internalcameraentity.h"
#include "Nebuladevice/render/internalgraphics/internalgraphicsserver.h"
#include "Nebuladevice/render/internalgraphics/internalstage.h"
#include "Nebuladevice/render/internalgraphics/internalview.h"
#include "Nebuladevice/foundation/messaging/staticmessagehandler.h"

using namespace Util;
using namespace Graphics;
using namespace InternalGraphics;

namespace Messaging
{
//------------------------------------------------------------------------------
/**
*/
__StaticHandler(CreateCameraEntity)
{
    Ptr<InternalCameraEntity> cameraEntity = InternalCameraEntity::Create();
    cameraEntity->SetTransform(msg->GetTransform());
    cameraEntity->SetVisible(msg->GetVisible());
    cameraEntity->SetSharedData(msg->GetSharedData());
    cameraEntity->SetCameraSettings(msg->GetCameraSettings());

    // attach camera entity to stage
    const Ptr<InternalStage>& stage = InternalGraphicsServer::Instance()->GetStageByName(msg->GetStageName());
    stage->AttachEntity(cameraEntity.cast<InternalGraphicsEntity>());

    // set return value
    msg->GetObjectRef()->Validate<InternalCameraEntity>(cameraEntity.get());
}

//------------------------------------------------------------------------------
/**
*/
__Handler(InternalCameraEntity, AttachCameraToView)
{
    const StringAtom& viewName = msg->GetViewName();
    n_assert(InternalGraphicsServer::Instance()->HasView(viewName));
    InternalGraphicsServer::Instance()->GetViewByName(viewName)->SetCameraEntity(obj);
}

//------------------------------------------------------------------------------
/**
*/
__Handler(InternalCameraEntity, RemoveCameraFromView)
{
    const StringAtom& viewName = msg->GetViewName();
    n_assert(InternalGraphicsServer::Instance()->HasView(viewName));
    const Ptr<InternalView>& view = InternalGraphicsServer::Instance()->GetViewByName(viewName);
    if (view->GetCameraEntity().isvalid())
    {
        n_assert(view->GetCameraEntity() == obj);
        view->SetCameraEntity(0);
    }
}

//------------------------------------------------------------------------------
/**
*/
__Handler(InternalCameraEntity, UpdateCameraEntity)
{
    obj->SetCameraSettings(msg->GetCameraSettings());
}

//------------------------------------------------------------------------------
/**
    Dispatcher method (must be positioned after the handler methods to
    prevent automatic instantiation).
*/
__Dispatcher(InternalCameraEntity)
{
    __Handle(InternalCameraEntity, AttachCameraToView)
    __Handle(InternalCameraEntity, RemoveCameraFromView)
    __Handle(InternalCameraEntity, UpdateCameraEntity);
    __HandleUnknown(InternalGraphicsEntity);
}

} // namespace Messaging