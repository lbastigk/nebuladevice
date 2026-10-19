#pragma once
//------------------------------------------------------------------------------
/**
    @class FX::AnimEventVibrationHandler
    
    This is the godsend animevent handler, to handle hotspot triggered vibrations
    
    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/render/animation/animeventhandlerbase.h"
#include "Nebuladevice/foundation/io/uri.h"
#include "Nebuladevice/foundation/timing/timer.h"

//------------------------------------------------------------------------------
namespace FX
{
class AnimEventVibrationHandler : public Animation::AnimEventHandlerBase
{
    __DeclareClass(AnimEventVibrationHandler);

public:
    /// constructor
    AnimEventVibrationHandler();
    /// destructor
    virtual ~AnimEventVibrationHandler();  

    /// handle a event
    virtual bool HandleEvent(const Animation::AnimEventInfo& event);
};
} // namespace FX
//------------------------------------------------------------------------------