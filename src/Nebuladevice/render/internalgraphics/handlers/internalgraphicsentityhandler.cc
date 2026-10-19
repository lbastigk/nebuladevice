//------------------------------------------------------------------------------
//  internalgraphicsentityhandler.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/graphics/graphicsprotocol.h"
#include "Nebuladevice/foundation/messaging/staticmessagehandler.h"
#include "Nebuladevice/render/internalgraphics/internalgraphicsentity.h"
#include "Nebuladevice/render/internalgraphics/internalstage.h"
#include "Nebuladevice/render/models/nodes/statenodeinstance.h"
#include "Nebuladevice/render/models/nodes/animatornodeinstance.h"
#include "Nebuladevice/render/renderutil/nodelookuputil.h"

using namespace CoreGraphics;
using namespace Models;
using namespace InternalGraphics;
using namespace Graphics;

namespace Messaging
{

//------------------------------------------------------------------------------
/**
*/
__Handler(InternalGraphicsEntity, DiscardGraphicsEntity)
{
    Ptr<InternalStage> stage = obj->GetStage();
    n_assert(stage.isvalid());
    stage->RemoveEntity(obj);    
    msg->GetObjectRef()->Invalidate();
}

//------------------------------------------------------------------------------
/**
*/
__Handler(InternalGraphicsEntity, UpdateTransform)
{
    obj->SetTransform(msg->GetTransform());
}

//------------------------------------------------------------------------------
/**
*/
__Handler(InternalGraphicsEntity, SetVisibility)
{
    obj->SetVisible(msg->GetVisible());
}

//------------------------------------------------------------------------------
/**
    Dispatcher method (must be positioned after the handler methods to
    prevent automatic instantiation).
*/
__Dispatcher(InternalGraphicsEntity)
{
    __Handle(InternalGraphicsEntity, UpdateTransform);
    __Handle(InternalGraphicsEntity, SetVisibility);
    __Handle(InternalGraphicsEntity, DiscardGraphicsEntity);
    __HandleUnknown(Core::RefCounted);
}

} // namespace Messaging