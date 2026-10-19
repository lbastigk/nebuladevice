//------------------------------------------------------------------------------
//  entityvisibility.cc
//  (C) 2010 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/visibility/visibilitycontainer.h"

namespace Visibility
{
__ImplementClass(Visibility::VisibilityContainer, 'VICT', Core::RefCounted);

using namespace Util;
using namespace Math;

//------------------------------------------------------------------------------
/**
*/
VisibilityContainer::VisibilityContainer()
{
}

//------------------------------------------------------------------------------
/**
*/
VisibilityContainer::~VisibilityContainer()
{
}

} // namespace Visibility
