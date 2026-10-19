#pragma once
#if !__PS3__
//------------------------------------------------------------------------------
/**
    @class Test::DelegateTableTest
    
    Test Messaging::DelegateTable functionality.
    
    (C) 2008 Radon Labs GmbH
*/
#include "NebulaDeviceTestLogic/testcase.h"

//------------------------------------------------------------------------------
namespace Test
{
class DelegateTableTest : public TestCase
{
    __DeclareClass(DelegateTableTest);
public:
    /// run the test
    virtual void Run();    
};

} // namespace Test
#endif
//------------------------------------------------------------------------------
    