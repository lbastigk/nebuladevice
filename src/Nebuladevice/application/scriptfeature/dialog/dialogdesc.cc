//------------------------------------------------------------------------------
//  script/dialog/dialogdesc.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/application/scriptfeature/dialog/dialogdesc.h"

namespace Script
{
__ImplementClass(Script::DialogDesc, 'DDES', Core::RefCounted);

//------------------------------------------------------------------------------
/**
*/
DialogDesc::DialogDesc() :
    isLocked(false),
    isConversation(false)
{
    // empty
}

} // namespace Script