#pragma once
//------------------------------------------------------------------------------
/**
    @class Base::MemoryIndexBufferLoaderBase
    
    Base resource loader class for initializing an index buffer from
    data in memory.
    
    (C) 2007 Radon Labs GmbH
*/
#include "Nebuladevice/render/resources/resourceloader.h"
#include "Nebuladevice/render/coregraphics/indexbuffer.h"
#include "Nebuladevice/render/coregraphics/indextype.h"

//------------------------------------------------------------------------------
namespace Base
{
class MemoryIndexBufferLoaderBase : public Resources::ResourceLoader
{
    __DeclareClass(MemoryIndexBufferLoaderBase);
public:
    /// constructor
    MemoryIndexBufferLoaderBase();
    /// setup index buffer from existing data, or provide 0 pointer if empty index buffer should be created
    void Setup(CoreGraphics::IndexType::Code indexType, SizeT numIndices, void* indexDataPtr, SizeT indexDataSize, CoreGraphics::IndexBuffer::Usage usage = CoreGraphics::IndexBuffer::UsageImmutable, CoreGraphics::IndexBuffer::Access access = CoreGraphics::IndexBuffer::AccessNone);

protected:
    CoreGraphics::IndexType::Code indexType;
    SizeT numIndices;
    void* indexDataPtr;
    SizeT indexDataSize;
	CoreGraphics::IndexBuffer::Usage usage;
	CoreGraphics::IndexBuffer::Access access;
};
        
} // namespace CoreGraphics
//------------------------------------------------------------------------------

