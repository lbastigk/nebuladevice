#pragma once
//------------------------------------------------------------------------------
/**
    @class InternalMultiplayer::PlayerInfo

    This struct is just used for messages at the moment.

    (C) 2009 Radon Labs GmbH
*/
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/util/string.h"
#include "Nebuladevice/addons/network/internalmultiplayer/handle.h"
#include "Nebuladevice/addons/network/internalmultiplayer/base/internalplayerbase.h"

namespace InternalMultiplayer
{
struct PlayerInfo 
{   
    Util::StringAtom gamerTag;
    PlayerHandle playerHandle;
    Base::InternalPlayerBase::SignInState signInState;
};
} // namespace InternalMultiplayer
//-------------------