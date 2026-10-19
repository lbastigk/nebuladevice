#pragma once
//------------------------------------------------------------------------------
/**
    @class Jobs::JobFuncDesc
    
    Platform-wrapper for a Job function descriptor.
    
    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/config.h"
#if __PS3__
#include "jobs/ps3/ps3jobfuncdesc.h"
namespace Jobs
{
typedef PS3::PS3JobFuncDesc JobFuncDesc;
}
#elif (NEBULA3_USE_SERIAL_JOBSYSTEM || __WII__)
#include "Nebuladevice/foundation/jobs/serial/serialjobfuncdesc.h"
namespace Jobs
{
typedef SerialJobFuncDesc JobFuncDesc;
}
#elif (__WIN32__ || __XBOX360__)
#include "Nebuladevice/foundation/jobs/tp/tpjobfuncdesc.h"
namespace Jobs
{
typedef TPJobFuncDesc JobFuncDesc;
}
#else
#error "Jobs::JobFuncDesc not implemented on this platform!"
#endif