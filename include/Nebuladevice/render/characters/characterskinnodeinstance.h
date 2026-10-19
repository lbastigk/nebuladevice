#pragma once
//------------------------------------------------------------------------------
/**
    @class Characters::CharacterSkinNodeInstance
    
    Implements per-instance functionality of a character skin node.
    
    (C) 2008 Radon Labs GmbH
*/
#include "Nebuladevice/render/models/nodes/shapenodeinstance.h"
#include "Nebuladevice/render/characters/characterinstance.h"
#include "Nebuladevice/render/characters/skinnedmeshrenderer.h"

//------------------------------------------------------------------------------
namespace Characters
{
class CharacterSkinNodeInstance : public Models::ShapeNodeInstance
{
    __DeclareClass(CharacterSkinNodeInstance);
public:
    /// constructor
    CharacterSkinNodeInstance();
    /// destructor
    virtual ~CharacterSkinNodeInstance();

    /// called when attached to ModelInstance
    virtual void Setup(const Ptr<Models::ModelInstance>& inst, const Ptr<Models::ModelNode>& node, const Ptr<Models::ModelNodeInstance>& parentNodeInst);
    /// called when removed from ModelInstance
    virtual void Discard();
    /// called from ModelEntity::OnNotifyCullingVisible
    virtual void OnNotifyCullingVisible(IndexT frameIndex, Timing::Time time);
    /// perform rendering
    virtual void Render();

protected:
    Ptr<CharacterInstance> characterInstance;
    Ptr<CoreGraphics::ShaderVariable> jointPaletteShdVar;
    Ptr<CoreGraphics::ShaderVariable> charIndexShdVar;
    SkinnedMeshRenderer::DrawHandle drawHandle;
};

} // namespace Characters
//------------------------------------------------------------------------------
    