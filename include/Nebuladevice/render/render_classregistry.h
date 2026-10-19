#pragma once
//------------------------------------------------------------------------------
/**
    @file render.h
    
    Add all class headers for classes which need dynamic object creation
    by class name or class fourcc here.
    
    (C) 2007 Radon Labs GmbH
*/
#include "Nebuladevice/render/models/modelnode.h"
#include "Nebuladevice/render/models/nodes/shapenode.h"
#include "Nebuladevice/render/characters/characternode.h"
#include "Nebuladevice/render/characters/characterskinnode.h"
#include "Nebuladevice/render/models/nodes/animatornodeinstance.h"
#include "Nebuladevice/render/particles/particlesystemnode.h"
#include "Nebuladevice/render/frame/framepass.h"
#include "Nebuladevice/render/terrain/terrainnode.h"
#include "Nebuladevice/render/terrain/terrainnodeinstance.h"

#if __WII__
#include "frame/wii/wiifsaaframepass.h"
#endif

namespace Models
{
    __RegisterClass(ModelNode);
    __RegisterClass(ShapeNode);
}

namespace Characters
{
    __RegisterClass(CharacterNode);
    __RegisterClass(CharacterSkinNode);
}

namespace Particles
{
    __RegisterClass(ParticleSystemNode);
}

namespace Frame
{
    __RegisterClass(FramePass);
}

namespace Terrain
{
	__RegisterClass(TerrainNode);
	__RegisterClass(TerrainNodeInstance);
}

#if __WII__
namespace Wii
{
    __RegisterClass(WiiFSAAFramePass);
}
#endif
