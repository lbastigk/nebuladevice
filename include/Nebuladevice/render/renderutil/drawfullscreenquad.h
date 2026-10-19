#pragma once
//------------------------------------------------------------------------------
/**
    @class RenderUtil::DrawFullScreenQuad
    
    Util class for rendering a full screen quad. Does not care about 
    shader setup!
    
    (C) 2009 Radon Labs GmbH
*/
#include "Nebuladevice/render/coregraphics/shaderinstance.h"
#include "Nebuladevice/render/coregraphics/shadervariable.h"
#include "Nebuladevice/render/coregraphics/vertexbuffer.h"
#include "Nebuladevice/render/coregraphics/primitivegroup.h"

//------------------------------------------------------------------------------
namespace RenderUtil
{
class DrawFullScreenQuad
{
public:
    /// constructor
    DrawFullScreenQuad();
    /// destructor
    ~DrawFullScreenQuad();

    /// setup the object
    void Setup(SizeT rtWidth, SizeT rtHeight);
    /// discard the object
    void Discard();
    /// return true if object is valid
    bool IsValid() const;
    /// draw the fullscreen quad
    void Draw();

private:
    Ptr<CoreGraphics::VertexBuffer> vertexBuffer;
    CoreGraphics::PrimitiveGroup primGroup;
    bool isValid;
};

//------------------------------------------------------------------------------
/**
*/
inline bool
DrawFullScreenQuad::IsValid() const
{
    return this->isValid;
}

} // namespace RnederUtil
//------------------------------------------------------------------------------
