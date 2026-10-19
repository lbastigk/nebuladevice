//------------------------------------------------------------------------------
//  testfoundation/main.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/foundation.h"
#include "Nebuladevice/foundation/core/coreserver.h"
#include "Nebuladevice/foundation/core/sysfunc.h"
#include "NebulaDeviceTestLogic/testrunner.h"
#include "NebulaDeviceTests/testaddon/databasetest.h"
#include "NebulaDeviceTests/testaddon/datasettest.h"

using namespace Core;
using namespace Test;

void
__cdecl main()
{
    // create Nebula3 runtime
    Ptr<CoreServer> coreServer = CoreServer::Create();
    coreServer->SetAppName("Nebula3 Foundation Tests");
    coreServer->Open();

    n_printf("NEBULA3 FOUNDATION TESTS\n");
    n_printf("========================\n");

    // setup and run test runner
    Ptr<TestRunner> testRunner = TestRunner::Create();
    testRunner->AttachTestCase(DatabaseTest::Create());
    testRunner->AttachTestCase(DatasetTest::Create());
    testRunner->Run(); 

    coreServer->Close();
    testRunner = 0;
    coreServer = 0;
    
    Core::SysFunc::Exit(0);
}
