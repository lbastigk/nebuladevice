#pragma once
//------------------------------------------------------------------------------
/**
    @class Graphics::MouseRenderer
    
    Main-thread proxy for the MouseRenderDevice (renders mouse pointers).
    
    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/refcounted.h"
#include "Nebuladevice/foundation/core/singleton.h"
#include "Nebuladevice/render/coregraphics/mousepointer.h"
#include "Nebuladevice/render/resources/resourceid.h"
#include "Nebuladevice/foundation/util/array.h"

//------------------------------------------------------------------------------
namespace Graphics
{
typedef CoreGraphics::MousePointer MousePointer;

class MouseRenderer : public Core::RefCounted
{
    __DeclareClass(MouseRenderer);
    __DeclareSingleton(MouseRenderer);
public:
    /// constructor
    MouseRenderer();
    /// destructor
    virtual ~MouseRenderer();
    
    /// pre-load mouse pointer textures
    void PreloadTextures(const Util::Array<Resources::ResourceId>& resIds);
    /// update mouse pointers
    void UpdatePointers(const Util::Array<MousePointer>& pointers);
};

} // namespace Graphics
//------------------------------------------------------------------------------
    