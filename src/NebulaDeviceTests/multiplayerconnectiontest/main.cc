//------------------------------------------------------------------------------
//  ps3test.cc
//  (C) 2009 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/core/types.h"
#include "Nebuladevice/foundation/core/coreserver.h"  
#include "NebulaDeviceTests/testbase/testrunner.h"
#include "NebulaDeviceTests/multiplayerconnectiontest/multiplayerconnectiontest.h"


using namespace Util;
using namespace IO;

//------------------------------------------------------------------------------
/**
*/
int
__cdecl main()
{
    Ptr<Core::CoreServer> coreServer = Core::CoreServer::Create();
    coreServer->SetCompanyName(StringAtom("Radon Labs GmbH"));
    coreServer->SetAppName(StringAtom("Multiplayer Connection Test"));
    coreServer->Open();

    Ptr<Test::TestRunner> runner = Test::TestRunner::Create();
    runner->AttachTestCase(Test::MultiplayerConnectionTest::Create());

    runner->Run();

    coreServer->Close();
    runner = 0;
    coreServer = 0;

    Core::SysFunc::Exit(0);
}