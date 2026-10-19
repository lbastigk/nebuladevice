//------------------------------------------------------------------------------
//  entityvisibility.cc
//  (C) 2010 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/visibility/visibilitycontext.h"

namespace Visibility
{
__ImplementClass(Visibility::VisibilityContext, 'VICO', Core::RefCounted);

using namespace Util;
using namespace Math;

//------------------------------------------------------------------------------
/**
*/
VisibilityContext::VisibilityContext():
    visibleFrameId(0)
{
}

//------------------------------------------------------------------------------
/**
*/
VisibilityContext::~VisibilityContext()
{
}

//------------------------------------------------------------------------------
/**
*/
void 
VisibilityContext::Setup(const Ptr<InternalGraphics::InternalGraphicsEntity>& entity)
{
    n_assert(entity.isvalid());
    this->gfxEntity = entity;
    this->boundingBox = entity->GetGlobalBoundingBox();
}

//------------------------------------------------------------------------------
/**
*/
void 
VisibilityContext::UpdateBoundingBox(const Math::bbox& box)
{
    this->boundingBox = box;
}
} // namespace Visibility
