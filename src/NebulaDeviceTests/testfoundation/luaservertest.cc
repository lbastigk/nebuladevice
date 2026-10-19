//------------------------------------------------------------------------------
//  luaservertest.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "NebulaDeviceTests/testfoundation/luaservertest.h"
//#include "Nebuladevice/addons/scripting/lua/luaserver.h"

namespace Test
{
__ImplementClass(Test::LuaServerTest, 'luat', Test::TestCase);

using namespace Util;

//------------------------------------------------------------------------------
/**
*/
void
LuaServerTest::Run()
{
/*
    Ptr<LuaServer> luaServer = LuaServer::Create();
    
    luaServer->Open();
    this->Verify(luaServer->IsOpen());

    luaServer->Eval("i = 3");

    luaServer->Close();
    this->Verify(!luaServer->IsOpen());
*/
}

} // namespace Test