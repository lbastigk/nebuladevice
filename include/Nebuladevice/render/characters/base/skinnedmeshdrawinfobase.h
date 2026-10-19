#pragma once
//------------------------------------------------------------------------------
/**
    @class Base::SkinnedMeshDrawInfoBase
    
    Contains per-instance information for a skinned-mesh draw operation. 
    Add platform-specific attributes by deriving from this class.
    This is usually only used by platforms which use software
    skinning.
    
    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/types.h"
#include "Nebuladevice/render/characters/characterinstance.h"
#include "Nebuladevice/render/coregraphics/mesh.h"

//------------------------------------------------------------------------------
namespace Base
{
struct SkinnedMeshDrawInfoBase
{
    Ptr<Characters::CharacterInstance> charInst;
    Ptr<CoreGraphics::Mesh> mesh;
};

} // namespace Base
//------------------------------------------------------------------------------
