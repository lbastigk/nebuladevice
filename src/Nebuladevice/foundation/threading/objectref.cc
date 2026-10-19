//------------------------------------------------------------------------------
//  objectref.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/threading/objectref.h"

namespace Threading
{
__ImplementClass(Threading::ObjectRef, 'OBJR', Core::RefCounted);

//------------------------------------------------------------------------------
/**
*/
ObjectRef::ObjectRef() :
    ref(0)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
ObjectRef::~ObjectRef()
{
    if (this->IsValid())
    {
        this->Invalidate();
    }
}        

} // namespace Threading