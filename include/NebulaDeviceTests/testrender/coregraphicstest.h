#pragma once
#ifndef TEST_COREGRAPHICSTEST_H
#define TEST_COREGRAPHICSTEST_H
//------------------------------------------------------------------------------
/** 
    @class Test::CoreGraphicsTest
    
    Base class for test cases which needs a CoreGraphics environment.
    
    (C) 2007 Radon Labs GmbH
*/
#include "NebulaDeviceTests/testbase/testcase.h"
#include "Nebuladevice/foundation/io/ioserver.h"
#include "Nebuladevice/foundation/io/iointerface.h"
#include "Nebuladevice/render/coregraphics/displaydevice.h"
#include "Nebuladevice/render/coregraphics/renderdevice.h"
#include "Nebuladevice/render/coregraphics/shaderserver.h"
#include "Nebuladevice/render/coregraphics/vertexlayoutserver.h"
#include "Nebuladevice/render/resources/resourcemanager.h"
#include "Nebuladevice/foundation/debug/debuginterface.h"
#include "Nebuladevice/foundation/http/httpinterface.h"

//------------------------------------------------------------------------------
namespace Test
{
class CoreGraphicsTest : public Test::TestCase
{
    __DeclareClass(CoreGraphicsTest);
protected:
    /// setup the required runtime
    bool SetupRuntime();
    /// shutdown the runtime
    void ShutdownRuntime();

    Ptr<IO::IoServer> ioServer;
    Ptr<IO::IoInterface> ioInterface;
    Ptr<Http::HttpInterface> httpInterface;
    Ptr<Debug::DebugInterface> debugInterface;
    Ptr<Resources::ResourceManager> resManager;
    Ptr<CoreGraphics::DisplayDevice> displayDevice;
    Ptr<CoreGraphics::RenderDevice> renderDevice;
    Ptr<CoreGraphics::ShaderServer> shaderServer;
    Ptr<CoreGraphics::VertexLayoutServer> vertexLayoutServer;
};

} // namespace Test    
//------------------------------------------------------------------------------
#endif
