#pragma once
//------------------------------------------------------------------------------
/**
    @class Frame::FrameServer
    
    Server object of the frame subsystem. Factory for FrameShaders.
    
    (C) 2007 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/refcounted.h"
#include "Nebuladevice/foundation/core/singleton.h"
#include "Nebuladevice/render/resources/resourceid.h"
#include "Nebuladevice/render/frame/frameshader.h"

//------------------------------------------------------------------------------
namespace Frame
{
class FrameServer : public Core::RefCounted
{
    __DeclareClass(FrameServer);
    __DeclareSingleton(FrameServer);
public:
    /// constructor
    FrameServer();
    /// destructor
    virtual ~FrameServer();
    /// open the frame server (loads all frame shaders)
    bool Open();
    /// close the frame server
    void Close();
    /// return true if open
    bool IsOpen() const;
    /// gain access to a frame shader by name, shader will be loaded if not happened yet
    Ptr<FrameShader> LookupFrameShader(const Resources::ResourceId& name);
    
private:
    /// load a frame shader
    void LoadFrameShader(const Resources::ResourceId& name);

    Util::Dictionary<Resources::ResourceId, Ptr<FrameShader> > frameShaders;
    bool isOpen;
};

//------------------------------------------------------------------------------
/**
*/
inline bool
FrameServer::IsOpen() const
{
    return this->isOpen;
}

} // namespace Frame
//------------------------------------------------------------------------------

    