//------------------------------------------------------------------------------
//  plane.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/math/plane.h"
#include "Nebuladevice/foundation/math/matrix44.h"

namespace Math
{

//------------------------------------------------------------------------------
/**
*/
plane
plane::transform(__PlaneArg p, const matrix44& m)
{
    return XMPlaneTransform(p.vec, m.mx);
}

} // namespace Math