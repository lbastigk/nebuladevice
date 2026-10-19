//------------------------------------------------------------------------------
//  shaderbase.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/render/coregraphics/base/shaderbase.h"
#include "Nebuladevice/render/coregraphics/shaderinstance.h"
#include "Nebuladevice/render/coregraphics/shader.h"

namespace Base
{
__ImplementClass(Base::ShaderBase, 'SHDB', Resources::Resource);

using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
*/
ShaderBase::ShaderBase() 
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
ShaderBase::~ShaderBase()
{
    n_assert(0 == this->shaderInstances.Size());
}

//------------------------------------------------------------------------------
/**
*/
Ptr<ShaderInstance>
ShaderBase::CreateShaderInstance()
{
    Ptr<ShaderInstance> newInst = ShaderInstance::Create();
    Ptr<ShaderBase> thisPtr(this);
    newInst->Setup(thisPtr.downcast<Shader>());
    this->shaderInstances.Append(newInst);
    return newInst;
}

//------------------------------------------------------------------------------
/**
*/
void
ShaderBase::DiscardShaderInstance(const Ptr<ShaderInstance>& inst)
{
    inst->Cleanup();
    IndexT i = this->shaderInstances.FindIndex(inst);
    n_assert(InvalidIndex != i);
    this->shaderInstances.EraseIndex(i);
}

} // namespace Base