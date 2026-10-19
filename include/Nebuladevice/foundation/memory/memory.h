#pragma once
//------------------------------------------------------------------------------
/**
    @class Memory::Memory
  
    Implements a private heap.
    
    (C) 2006 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/config.h"

#if (__WIN32__ || __XBOX360__)
#include "Nebuladevice/foundation/memory/win360/win360memory.h"
#elif __WII__
#include "memory/wii/wiimemory.h"
#elif __PS3__
#include "memory/ps3/ps3memory.h"
#elif __OSX__
#include "Nebuladevice/foundation/memory/osx/osxmemory.h"
#else
#error "UNKNOWN PLATFORM"
#endif
