#pragma once
//------------------------------------------------------------------------------
/**
    @class Base::MemoryVertexBufferLoaderBase
    
    Base resource loader class for initializing an vertex buffer from
    data in memory.
    
    (C) 2007 Radon Labs GmbH
*/
#include "Nebuladevice/render/resources/resourceloader.h"
#include "Nebuladevice/render/coregraphics/vertexcomponent.h"
#include "Nebuladevice/render/coregraphics/vertexbuffer.h"

//------------------------------------------------------------------------------
namespace Base
{
class MemoryVertexBufferLoaderBase : public Resources::ResourceLoader
{
    __DeclareClass(MemoryVertexBufferLoaderBase);
public:
    /// constructor
    MemoryVertexBufferLoaderBase();
    /// setup vertex buffer data, must remain valid until OnLoadRequested() is called!
    void Setup(const Util::Array<CoreGraphics::VertexComponent>& vertexComponents, SizeT numVertices, void* vertexDataPtr, SizeT vertexDataSize, CoreGraphics::VertexBuffer::Usage usage, CoreGraphics::VertexBuffer::Access access);

protected:
    Util::Array<CoreGraphics::VertexComponent> vertexComponents;
    SizeT numVertices;
    void* vertexDataPtr;
    SizeT vertexDataSize;
	CoreGraphics::VertexBuffer::Usage usage;
	CoreGraphics::VertexBuffer::Access access;
};

} // namespace Base
//------------------------------------------------------------------------------

