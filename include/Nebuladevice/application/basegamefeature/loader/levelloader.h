#pragma once
//------------------------------------------------------------------------------
/**
    @class BaseGameFeature::LevelLoader
    
    Helper class for loading a complete level from the world database.
    
    (C) 2007 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/types.h"
#include "Nebuladevice/foundation/util/string.h"

//------------------------------------------------------------------------------
namespace BaseGameFeature
{
class LevelLoader
{
public:
    /// load a complete level from the world database
    static bool Load(const Util::String& levelName);
};

} // namespace BaseGameFeature
//------------------------------------------------------------------------------
