#pragma once
//------------------------------------------------------------------------------
/**
    @class BaseGameFeature::SystemTimeSource
    
    Provides the time for the various system features.
    These features has to get the time from this timesource.

    Access the SystemTimeSource object as Singleton:

    Time sysTime = SystemTimeSource::Instance()->GetTime();

    (C) 2007 Radon Labs GmbH
*/
#include "Nebuladevice/application/basegamefeature/basegametiming/timesource.h"
#include "Nebuladevice/foundation/core/singleton.h"

//------------------------------------------------------------------------------
namespace BaseGameFeature
{
class SystemTimeSource : public TimeSource
{
    __DeclareClass(SystemTimeSource);
    __DeclareSingleton(SystemTimeSource);

public:
    /// constructor
    SystemTimeSource();
    /// destructor
    virtual ~SystemTimeSource();
};

} // namespace BaseGameFeature
//------------------------------------------------------------------------------
