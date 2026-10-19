//------------------------------------------------------------------------------
//  ps3mathtest_ps3/main.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/system/appentry.h"
#include "Nebuladevice/foundation/core/coreserver.h"
#include "NebulaDeviceTests/testbase/testrunner.h"

// tests
#include "NebulaDeviceTests/mathtest/scalartest.h"
#include "NebulaDeviceTests/mathtest/float4test.h"
#include "NebulaDeviceTests/mathtest/matrix44test.h"
#include "NebulaDeviceTests/mathtest/quaterniontest.h"
#include "NebulaDeviceTests/mathtest/vectortest.h"
#include "NebulaDeviceTests/mathtest/pointtest.h"
#include "NebulaDeviceTests/mathtest/planetest.h"
#include "NebulaDeviceTests/testbase/stackdebug.h"

/*
#if __PS3__
#include <sys/process.h>
// change stacksize from default 64kB to 96kB
SYS_PROCESS_PARAM (1001, 0x18000) // (priority, stack size)
#endif
*/

ImplementNebulaApplication();

using namespace Core;
using namespace Test;

//------------------------------------------------------------------------------
/**
*/
void
NebulaMain(const Util::CommandLineArgs& args)
{
    STACK_CHECKPOINT("NebulaMain");

    // create Nebula3 runtime
    Ptr<CoreServer> coreServer = CoreServer::Create();
    coreServer->SetAppName(Util::StringAtom("Nebula3 Foundation Math-Tests"));
    coreServer->Open();

    n_printf("NEBULA3 FOUNDATION MATH-TESTS\n");
    n_printf("========================\n");

	// setup and run test runner
    Ptr<TestRunner> testRunner = TestRunner::Create();
    testRunner->AttachTestCase(ScalarTest::Create());
    testRunner->AttachTestCase(Float4Test::Create());
	testRunner->AttachTestCase(Matrix44Test::Create());
	testRunner->AttachTestCase(QuaternionTest::Create());
	testRunner->AttachTestCase(VectorTest::Create());
	testRunner->AttachTestCase(PointTest::Create());
    testRunner->AttachTestCase(PlaneTest::Create());

    testRunner->Run(); 

    coreServer->Close();
    testRunner = 0;
    coreServer = 0;
    
    Core::SysFunc::Exit(0);
}
