#pragma once
//------------------------------------------------------------------------------
/**
    @class BaseGameFeature::TimingTimeSource
    
    Provides timing information for the Timing logic.
    
    (C) 2007 Radon Labs GmbH
*/
#include "Nebuladevice/application/basegamefeature/basegametiming/timesource.h"
#include "Nebuladevice/foundation/core/singleton.h"

//------------------------------------------------------------------------------
namespace BaseGameFeature
{
class GameTimeSource : public TimeSource
{
    __DeclareClass(GameTimeSource);
    __DeclareSingleton(GameTimeSource);

public:
    /// constructor
    GameTimeSource();
    /// destructor
    virtual ~GameTimeSource();
};

} // namespace BaseGameFeature
//------------------------------------------------------------------------------

