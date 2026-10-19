#pragma once
//------------------------------------------------------------------------------
/**
    @class FX::FXRenderModule

    A central client-side object for the FX system

    (C) 2009 Radon Labs GmbH
*/

#include "Nebuladevice/foundation/core/singleton.h"
#include "Nebuladevice/render/rendermodules/rendermodule.h"

namespace FX
{
class FXRenderModule : public RenderModules::RenderModule
{
__DeclareClass(FXRenderModule);
__DeclareSingleton(FXRenderModule);

public:
    
    /// Constructor
    FXRenderModule();
    /// Destructor
    virtual ~FXRenderModule();

    /// Setup the render module
    virtual void Setup();
    /// Discard the render module
    virtual void Discard();

private:

};
} // namespace FX