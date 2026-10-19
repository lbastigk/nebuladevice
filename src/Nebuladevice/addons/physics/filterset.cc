//------------------------------------------------------------------------------
//  physics/filterset.cc
//  (C) 2005 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/addons/physics/filterset.h"
#include "Nebuladevice/addons/physics/shape.h"
#include "Nebuladevice/addons/physics/physicsentity.h"
#include "Nebuladevice/addons/physics/rigidbody.h"

namespace Physics
{
//------------------------------------------------------------------------------
/**
*/
bool
FilterSet::CheckShape(Shape* shape) const
{
    n_assert(shape);
    if (0 == (this->collideBits & shape->GetCategoryBits()))
    {
        return true;
    }
    if (this->CheckMaterialType(shape->GetMaterialType()))
    {
        return true;
    }
    PhysicsEntity* entity = shape->GetEntity();
    if (entity && this->CheckEntityId(entity->GetUniqueId()))
    {
        return true;
    }
    RigidBody* rigidBody = shape->GetRigidBody();
    if (rigidBody && this->CheckRigidBodyId(rigidBody->GetUniqueId()))
    {
        return true;
    }
    return false;
}

};
