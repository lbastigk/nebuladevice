#pragma once
//------------------------------------------------------------------------------
/**
    @class Base::UIRendererBase
  
    Base class for internal UI rendering.
    
    (C) 2008 Radon Labs GmbH
*/    
#include "Nebuladevice/foundation/core/refcounted.h"
#include "Nebuladevice/foundation/core/singleton.h"
#include "Nebuladevice/foundation/math/rectangle.h"
#include "Nebuladevice/addons/ui/rt/coreuielement.h"
#include "Nebuladevice/foundation/threading/threadid.h"
#include "Nebuladevice/render/resources/managedtexture.h"
#include "Nebuladevice/render/resources/resourcemanager.h"
#include "Nebuladevice/render/coregraphics/shaderinstance.h"
#include "Nebuladevice/foundation/util/stringatom.h"
#include "Nebuladevice/foundation/timing/timer.h"

//------------------------------------------------------------------------------
namespace Base
{
class CoreUIRendererBase : public Core::RefCounted
{
    __DeclareClass(CoreUIRendererBase);
    __DeclareSingleton(CoreUIRendererBase);
public:
    /// constructor
    CoreUIRendererBase();
    /// destructor
    virtual ~CoreUIRendererBase();
    
    /// open the the ui renderer
    void Setup();
    /// close the ui renderer
    void Discard();
    /// check if ui renderer open
    bool IsValid() const;

    /// set UI elements to render for this frame
    void SetElements(const Util::Array<CoreUI::CoreUIElement>& elements);
    /// draw the accumulated ui
    void DrawElements(const Ptr<CoreGraphics::ShaderInstance>& shdInst);
    /// load texture
    void LoadTexture(const Resources::ResourceId& resId);
    /// unload texture
    void UnloadTexture(const Resources::ResourceId& resId);
    /// check texture resources
    bool CheckTexturesLoaded() const;
    /// return number of elements in current frame
    SizeT GetNumElements() const;

protected:
    bool isValid;
    Util::Dictionary<int, CoreUI::CoreUIElement> sortedElements;
    Util::Dictionary<Resources::ResourceId, Ptr<Resources::ManagedTexture> > texturePool;
};

//------------------------------------------------------------------------------
/**
*/
inline bool
CoreUIRendererBase::IsValid() const
{
    return this->isValid;
}

//------------------------------------------------------------------------------
/**
*/
inline SizeT
CoreUIRendererBase::GetNumElements() const
{
    return this->sortedElements.Size();
}

} // namespace Base
//------------------------------------------------------------------------------
