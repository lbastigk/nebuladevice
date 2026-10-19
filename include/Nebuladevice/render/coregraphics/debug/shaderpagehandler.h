#pragma once
#ifndef DEBUG_SHADERPAGEHANDLER_H
#define DEBUG_SHADERPAGEHANDLER_H
//------------------------------------------------------------------------------
/**
    @class Debug::ShaderPageHandler
  
    Provide a HTML debug page for shaders.
    
    Usage:
    http://host/shader                      - list of all shaders
    http://host/shader?shaderinfo=[resId]   - information about a specific shader
    
    (C) 2007 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/http/httprequesthandler.h"
#include "Nebuladevice/render/resources/resourceid.h"
#include "Nebuladevice/foundation/http/html/htmlpagewriter.h"
#include "Nebuladevice/render/coregraphics/shader.h"
#include "Nebuladevice/render/models/modelnodeinstance.h"

//------------------------------------------------------------------------------
namespace Debug
{
class ShaderPageHandler : public Http::HttpRequestHandler
{
    __DeclareClass(ShaderPageHandler);
public:
    /// constructor
    ShaderPageHandler();
    /// handle a http request, the handler is expected to fill the content stream with response data
    virtual void HandleRequest(const Ptr<Http::HttpRequest>& request);

private:
    /// display information about specific shader
    Http::HttpStatus::Code HandleShaderInfoRequest(const Resources::ResourceId& resId, const Ptr<IO::Stream>& responseContentStream);
    /// write a shader variable table to the HTML stream
    void WriteShaderVariableTable(const Ptr<Http::HtmlPageWriter>& htmlWriter, const Util::Array<Ptr<CoreGraphics::ShaderVariable> >& vars);
    /// check if any modelnodeinstance has given shader resid
    bool HasShaderInstance(const Ptr<Models::ModelNodeInstance>& node, const Resources::ResourceId& resId);
};

} // namespace Debug
//------------------------------------------------------------------------------
#endif
