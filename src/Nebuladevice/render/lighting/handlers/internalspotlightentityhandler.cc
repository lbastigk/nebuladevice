//------------------------------------------------------------------------------
//  internalspotlightentityhandler.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/lighting/internalspotlightentity.h"
#include "Nebuladevice/render/graphics/graphicsprotocol.h"
#include "Nebuladevice/foundation/messaging/staticmessagehandler.h"
#include "Nebuladevice/render/lighting/internalgloballightentity.h"
#include "Nebuladevice/render/internalgraphics/internalgraphicsserver.h"
#include "Nebuladevice/render/internalgraphics/internalstage.h"

using namespace Util;
using namespace Graphics;
using namespace InternalGraphics;
using namespace Lighting;

namespace Messaging
{

//------------------------------------------------------------------------------
/**
*/
__StaticHandler(CreateSpotLightEntity)
{
    // create a new spotlight entity
    Ptr<Lighting::InternalSpotLightEntity> lightEntity = Lighting::InternalSpotLightEntity::Create();
    lightEntity->SetSharedData(msg->GetSharedData());
    lightEntity->SetTransform(msg->GetTransform());
    lightEntity->SetVisible(msg->GetVisible());
    lightEntity->SetColor(msg->GetLightColor());
    lightEntity->SetCastShadows(msg->GetCastShadows());
    lightEntity->SetProjMapUvOffsetAndScale(msg->GetProjMapUvOffsetAndScale());

    // lookup stage and attach entity
    const Ptr<InternalStage>& stage = InternalGraphicsServer::Instance()->GetStageByName(msg->GetStageName());
    stage->AttachEntity(lightEntity.cast<InternalGraphicsEntity>());

    // set return value
    msg->GetObjectRef()->Validate<Lighting::InternalSpotLightEntity>(lightEntity.get());
}

//------------------------------------------------------------------------------
/**
*/
__Dispatcher(InternalSpotLightEntity)
{
    __HandleUnknown(InternalAbstractLightEntity);
}

} // namespace Messaging
