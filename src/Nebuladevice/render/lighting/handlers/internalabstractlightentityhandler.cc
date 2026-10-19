//------------------------------------------------------------------------------
//  internalabstractlightentityhandler.cc
//  (C) 2010 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/graphics/graphicsprotocol.h"
#include "Nebuladevice/foundation/messaging/staticmessagehandler.h"
#include "Nebuladevice/render/lighting/internalabstractlightentity.h"

using namespace Graphics;
using namespace Lighting;
using namespace InternalGraphics;

namespace Messaging
{

//------------------------------------------------------------------------------
/**
*/
__Handler(InternalAbstractLightEntity, SetLightColor)
{
    obj->SetColor(msg->GetColor());
}

//------------------------------------------------------------------------------
/**
*/
__Handler(InternalAbstractLightEntity, SetLightCastShadows)
{
    obj->SetCastShadows(msg->GetCastShadows());
}

//------------------------------------------------------------------------------
/**
*/
__Dispatcher(InternalAbstractLightEntity)
{
    __Handle(InternalAbstractLightEntity, SetLightColor);
    __Handle(InternalAbstractLightEntity, SetLightCastShadows);
    __HandleUnknown(InternalGraphicsEntity);
}

} // namespace Messaging
