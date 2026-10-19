//------------------------------------------------------------------------------
//  testrender/main.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/foundation.h"
#include "Nebuladevice/render/render_classregistry.h"
#include "Nebuladevice/foundation/core/coreserver.h"
#include "Nebuladevice/foundation/core/sysfunc.h"
#include "NebulaDeviceTests/testbase/testrunner.h"
#include "NebulaDeviceTests/testrender/loadmeshtest.h"
#include "NebulaDeviceTests/testrender/loadtexturetest.h"
#include "NebulaDeviceTests/testrender/modelloadsavetest.h"
#include "NebulaDeviceTests/testrender/shadertest.h"
#include "NebulaDeviceTests/testrender/simplemeshmappertest.h"
#include "NebulaDeviceTests/testrender/simpletexturemappertest.h"
#include "NebulaDeviceTests/testrender/n2modelloadertest.h"
#include "NebulaDeviceTests/testrender/loadanimationtest.h"
#include "NebulaDeviceTests/testrender/animsamplemixtest.h"
#include "NebulaDeviceTests/testrender/animsequencertest.h"
#include "NebulaDeviceTests/testrender/attributetabletest.h"
#include "NebulaDeviceTests/testrender/attributecontainertest.h"

using namespace Core;
using namespace Test;

void
__cdecl main()
{
    // create Nebula3 runtime
    Ptr<CoreServer> coreServer = CoreServer::Create();
    coreServer->SetAppName(Util::StringAtom("Nebula3 Render Tests"));
    coreServer->Open();

    n_printf("NEBULA3 RENDER TESTS\n");
    n_printf("====================\n");

    // setup and run test runner
    Ptr<TestRunner> testRunner = TestRunner::Create();
    //testRunner->AttachTestCase(AttributeContainerTest::Create());
    //testRunner->AttachTestCase(AttributeTableTest::Create());
    //testRunner->AttachTestCase(AnimSequencerTest::Create());
    //testRunner->AttachTestCase(AnimSampleMixTest::Create());
    testRunner->AttachTestCase(LoadAnimationTest::Create());
    /*
    testRunner->AttachTestCase(N2ModelLoaderTest::Create());
    testRunner->AttachTestCase(LoadMeshTest::Create());
    testRunner->AttachTestCase(LoadTextureTest::Create());
    testRunner->AttachTestCase(ModelLoadSaveTest::Create());
    testRunner->AttachTestCase(ShaderTest::Create());
    testRunner->AttachTestCase(SimpleMeshMapperTest::Create());
    testRunner->AttachTestCase(SimpleTextureMapperTest::Create());
    */
    testRunner->Run(); 

    coreServer->Close();
    testRunner = 0;
    coreServer = 0;
    
    Core::SysFunc::Exit(0);
}
