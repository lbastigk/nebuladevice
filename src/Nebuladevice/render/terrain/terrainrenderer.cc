//------------------------------------------------------------------------------
//  terrainrenderer.cc
//  (C) 2011 xiongyouyi
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/terrain/terrainrenderer.h"


namespace Terrain
{
__ImplementClass(Terrain::TerrainRenderer, 'TERR', Core::RefCounted);
__ImplementSingleton(Terrain::TerrainRenderer);


//------------------------------------------------------------------------------
/**
*/
TerrainRenderer::TerrainRenderer()
{
	__ConstructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
TerrainRenderer::~TerrainRenderer()
{
	__DestructSingleton;
}

} // namespace Terrain