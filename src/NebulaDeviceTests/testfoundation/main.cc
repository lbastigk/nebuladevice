//------------------------------------------------------------------------------
//  testfoundation/main.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/foundation.h"
#include "Nebuladevice/foundation/core/coreserver.h"
#include "Nebuladevice/foundation/core/sysfunc.h"
#include "Nebuladevice/foundation/io/gamecontentserver.h"
#include "NebulaDeviceTests/testbase/testrunner.h"
#include "NebulaDeviceTests/testfoundation/stringtest.h"
#include "NebulaDeviceTests/testfoundation/arraytest.h"
#include "NebulaDeviceTests/testfoundation/stacktest.h"
#include "NebulaDeviceTests/testfoundation/listtest.h"
#include "NebulaDeviceTests/testfoundation/dictionarytest.h"
#include "NebulaDeviceTests/testfoundation/fixedarraytest.h"
#include "NebulaDeviceTests/testfoundation/fixedtabletest.h"
#include "NebulaDeviceTests/testfoundation/hashtabletest.h"
#include "NebulaDeviceTests/testfoundation/queuetest.h"
#include "NebulaDeviceTests/testfoundation/memorystreamtest.h"
#include "NebulaDeviceTests/testfoundation/guidtest.h"
#include "NebulaDeviceTests/testfoundation/fileservertest.h"
#include "NebulaDeviceTests/testfoundation/uritest.h"
#include "NebulaDeviceTests/testfoundation/textreaderwritertest.h"
#include "NebulaDeviceTests/testfoundation/messagereaderwritertest.h"
#include "NebulaDeviceTests/testfoundation/xmlreaderwritertest.h"
#include "NebulaDeviceTests/testfoundation/binaryreaderwritertest.h"
#include "NebulaDeviceTests/testfoundation/uritest.h"
#include "NebulaDeviceTests/testfoundation/mediatypetest.h"
#include "NebulaDeviceTests/testfoundation/varianttest.h"
#include "NebulaDeviceTests/testfoundation/iointerfacetest.h"
#include "NebulaDeviceTests/testfoundation/cmdlineargstest.h"
#include "NebulaDeviceTests/testfoundation/streamservertest.h"
#include "NebulaDeviceTests/testfoundation/luaservertest.h"
#include "NebulaDeviceTests/testfoundation/zipfstest.h"
#include "float4test.h"
#include "matrix44test.h"
#include "NebulaDeviceTests/testfoundation/threadtest.h"
#include "NebulaDeviceTests/testfoundation/memorypooltest.h"
#include "NebulaDeviceTests/testfoundation/runlengthcodectest.h"
#include "NebulaDeviceTests/testfoundation/ringbuffertest.h"
#include "NebulaDeviceTests/testfoundation/excelxmlreadertest.h"
#include "NebulaDeviceTests/testfoundation/delegatetest.h"
#include "NebulaDeviceTests/testfoundation/delegatetabletest.h"
#include "NebulaDeviceTests/testfoundation/httpclienttest.h"
#include "NebulaDeviceTests/testfoundation/bxmlreadertest.h"

using namespace Core;
using namespace Test;

int
__cdecl main()
{
    // create Nebula3 runtime
    Ptr<CoreServer> coreServer = CoreServer::Create();
    coreServer->SetAppName(Util::StringAtom("Nebula3 Foundation Tests"));
    coreServer->Open();

    Ptr<IO::GameContentServer> gameContentServer = IO::GameContentServer::Create();
    gameContentServer->SetTitle("RL Test Title");
    gameContentServer->SetTitleId("RLTITLEID");
    gameContentServer->SetVersion("1.00");
    gameContentServer->Setup();

    n_printf("NEBULA3 FOUNDATION TESTS\n");
    n_printf("========================\n");

    // setup and run test runner
    Ptr<TestRunner> testRunner = TestRunner::Create();
    testRunner->AttachTestCase(BXmlReaderTest::Create());
    testRunner->AttachTestCase(HttpClientTest::Create());
    #if !__PS3__
    testRunner->AttachTestCase(DelegateTableTest::Create());
    testRunner->AttachTestCase(DelegateTest::Create());
    #endif
    testRunner->AttachTestCase(ExcelXmlReaderTest::Create());
    testRunner->AttachTestCase(RingBufferTest::Create());
    testRunner->AttachTestCase(RunLengthCodecTest::Create());
    testRunner->AttachTestCase(MemoryPoolTest::Create());
    testRunner->AttachTestCase(Matrix44Test::Create());
    testRunner->AttachTestCase(Float4Test::Create());
    testRunner->AttachTestCase(ZipFSTest::Create());
    testRunner->AttachTestCase(LuaServerTest::Create());
    testRunner->AttachTestCase(StreamServerTest::Create());
    testRunner->AttachTestCase(CmdLineArgsTest::Create());
    testRunner->AttachTestCase(MediaTypeTest::Create());
    testRunner->AttachTestCase(URITest::Create());
    testRunner->AttachTestCase(StringTest::Create());   
    testRunner->AttachTestCase(ArrayTest::Create());
    testRunner->AttachTestCase(StackTest::Create());
    testRunner->AttachTestCase(ListTest::Create());
    testRunner->AttachTestCase(DictionaryTest::Create());
    testRunner->AttachTestCase(FixedArrayTest::Create());
    testRunner->AttachTestCase(FixedTableTest::Create());
    testRunner->AttachTestCase(HashTableTest::Create());
    testRunner->AttachTestCase(QueueTest::Create());
    testRunner->AttachTestCase(MemoryStreamTest::Create());
    testRunner->AttachTestCase(GuidTest::Create());
    testRunner->AttachTestCase(FileServerTest::Create());
    testRunner->AttachTestCase(TextReaderWriterTest::Create());
    testRunner->AttachTestCase(MessageReaderWriterTest::Create());
    testRunner->AttachTestCase(XmlReaderWriterTest::Create());
    testRunner->AttachTestCase(BinaryReaderWriterTest::Create());
    testRunner->AttachTestCase(VariantTest::Create());
    testRunner->AttachTestCase(IOInterfaceTest::Create());
    testRunner->AttachTestCase(ThreadTest::Create());
    testRunner->Run(); 

    gameContentServer->Discard();
    gameContentServer = 0;
    coreServer->Close();
    testRunner = 0;
    coreServer = 0;
    
    Core::SysFunc::Exit(0);
}
