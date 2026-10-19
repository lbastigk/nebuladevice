#pragma once
//------------------------------------------------------------------------------
/**
    @class CoreAnimation::AnimEventEmitter
  
    The AnimEventEmitter collects all animevents which are active in the 
    given time range.
    
    This emitter does NOT consider if the clip is used animation driven or not.
    It always calculates the whole animation duration, not one key-decremented like
    the play clip job in case of animation driven usage!

    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/util/array.h"
#include "Nebuladevice/render/coreanimation/animclip.h"
#include "Nebuladevice/render/coreanimation/animevent.h"

//------------------------------------------------------------------------------
namespace CoreAnimation
{
class AnimEventEmitter
{
public:
    static Util::Array<AnimEvent> EmitAnimEvents(const AnimClip& clip, Timing::Tick start, Timing::Tick end, bool isInfitine);
};

} // namespace CoreAnimation
//------------------------------------------------------------------------------