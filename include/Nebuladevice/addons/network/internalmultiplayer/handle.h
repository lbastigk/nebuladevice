#pragma once
//------------------------------------------------------------------------------
/**
    @class InternalMultiplayer::Handle
    
    A private Handle typedef to safely pass data between a server and
    a client thread. Don't assume anything about the content of the
    Handle!
    
    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/types.h"
#include "Nebuladevice/foundation/core/refcounted.h"

//------------------------------------------------------------------------------
namespace InternalMultiplayer
{
typedef Ptr<Core::RefCounted> PlayerHandle;
typedef Ptr<Core::RefCounted> SessionHandle;
}
//------------------------------------------------------------------------------
