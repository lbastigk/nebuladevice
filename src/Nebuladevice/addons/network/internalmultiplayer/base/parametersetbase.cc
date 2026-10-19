//------------------------------------------------------------------------------
//  parametersetbase.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/addons/network/internalmultiplayer/base/parametersetbase.h"

namespace Base
{
__ImplementClass(ParameterSetBase, 'PMSB', Core::RefCounted);

//------------------------------------------------------------------------------
/**
*/
ParameterSetBase::ParameterSetBase()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
ParameterSetBase::~ParameterSetBase()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
bool 
ParameterSetBase::IsEqual( const Ptr<Base::ParameterSetBase>& other ) const
{
    n_error("Overwrite in subclass!");
    return false;
}
} // namespace Base
