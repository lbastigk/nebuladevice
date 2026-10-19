#ifndef TEST_TESTRUNNER_H
#define TEST_TESTRUNNER_H
//------------------------------------------------------------------------------
/**
    @class Test::TestRunner
    
    The test runner class which runs all test cases.
    
    (C) 2006 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/refcounted.h"
#include "Nebuladevice/foundation/core/ptr.h"
#include "Nebuladevice/foundation/util/array.h"
#include "NebulaDeviceTestLogic/testcase.h"

//------------------------------------------------------------------------------
namespace Test
{
class TestRunner : public Core::RefCounted
{
    __DeclareClass(TestRunner);
public:
    /// attach a test
    void AttachTestCase(TestCase* testCase);
    /// run the tests
    void Run();

private:
    Util::Array<Ptr<TestCase> > testCases;
};

};    
//------------------------------------------------------------------------------
#endif