//------------------------------------------------------------------------------
//  network/multiplayer/base/parameterresolverbase.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/addons/network/internalmultiplayer/base/parameterresolverbase.h"

namespace Base
{
__ImplementClass(ParameterResolverBase, 'PRSB', Core::RefCounted);

//------------------------------------------------------------------------------
/**
*/
ParameterResolverBase::ParameterResolverBase()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
ParameterResolverBase::~ParameterResolverBase()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
bool 
ParameterResolverBase::CompareParameterSet( const Ptr<ParameterResolverBase>& other )
{
    return this->GetParameterSet()->IsEqual(other->GetParameterSet());
}

} // namespace Base
