#pragma once
//------------------------------------------------------------------------------
/**
    @class Animator::AnimatorInstance
    
    Legacy N2 crap!

    (C) 2008 Radon Labs GmbH
*/

#include "Nebuladevice/render/models/modelnodeinstance.h"
#include "Nebuladevice/foundation/timing/time.h"
#include "Nebuladevice/render/models/nodes/animlooptype.h"
#include "Nebuladevice/render/models/nodes/animkeyarray.h"
#include "Nebuladevice/render/models/nodes/animkey.h"
#include "Nebuladevice/foundation/math/vector.h"
#include "Nebuladevice/render/coregraphics/shadervariable.h"
#include "Nebuladevice/render/coregraphics/shadervariableinstance.h"

namespace Models
{
class AnimatorNodeInstance : public Models::ModelNodeInstance
{
__DeclareClass(AnimatorNodeInstance);
public:
    /// Constructor
    AnimatorNodeInstance();
    /// Destructor
    virtual ~AnimatorNodeInstance();
    /// setup the model node instance
    virtual void Setup(const Ptr<ModelInstance>& inst, const Ptr<ModelNode>& node, const Ptr<ModelNodeInstance>& parentNodeInst);    
    /// called from ModelEntity::OnNotifyCullingVisible
    virtual void OnNotifyCullingVisible(IndexT frameIndex, Timing::Time time);

    virtual void OverwriteAnimationTime(Timing::Time time);
private:
    /// called by scene node objects which wish to be animated by this object
    void Animate(Timing::Time time);
    /// called when the node becomes visible with current time
    virtual void OnShow(Timing::Time time);

    struct AnimatedNode
    {
        Ptr<ModelNodeInstance> node;
        Ptr<CoreGraphics::ShaderVariableInstance> shaderVar;
    };

    Util::Array<Util::Array<AnimatedNode> > animSection;
    Timing::Time startTime;
    Timing::Time overWrittenAnimTime;
};
__RegisterClass(AnimatorNodeInstance);

//------------------------------------------------------------------------------
/**
*/
inline void
AnimatorNodeInstance::OverwriteAnimationTime(Timing::Time time)
{
    this->overWrittenAnimTime = this->startTime + time;
}
};