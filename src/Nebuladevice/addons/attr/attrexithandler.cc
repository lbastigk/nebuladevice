//------------------------------------------------------------------------------
//  attrexithandler.cc
//  (C) 2008 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/addons/attr/attrexithandler.h"
#include "Nebuladevice/addons/attr/attributedefinitionbase.h"

namespace Attr
{

//------------------------------------------------------------------------------
/**
*/
void
AttrExitHandler::OnExit() const
{
    // cleanup dynamic attributes
    AttributeDefinitionBase::ClearDynamicAttributes();
}

} // namespace Attr