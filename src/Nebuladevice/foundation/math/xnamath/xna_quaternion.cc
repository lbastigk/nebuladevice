//------------------------------------------------------------------------------
//  xna_quaternion.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/math/float4.h"
#include "Nebuladevice/foundation/math/matrix44.h"
#include "Nebuladevice/foundation/system/byteorder.h"

namespace Math
{

//------------------------------------------------------------------------------
/**
*/
quaternion
quaternion::rotationmatrix(const matrix44& m)
{
    return XMQuaternionRotationMatrix(m.mx);
}


}

