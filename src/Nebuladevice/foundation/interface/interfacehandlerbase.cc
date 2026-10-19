//------------------------------------------------------------------------------
//  interfacehandlerbase.cc
//  (C) 2008 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/interface/interfacehandlerbase.h"

namespace Interface
{
__ImplementClass(Interface::InterfaceHandlerBase, 'IFHB', Messaging::Handler);

//------------------------------------------------------------------------------
/**
*/
InterfaceHandlerBase::InterfaceHandlerBase()
{
    // empty
}     

//------------------------------------------------------------------------------
/**
*/
void
InterfaceHandlerBase::DoWork()
{
    // empty
}

} // namespace Interface