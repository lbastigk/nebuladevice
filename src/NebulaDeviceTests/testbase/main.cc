//------------------------------------------------------------------------------
//  main.cc
//  Test the legacy test infrastructure itself.
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/app/consoleapplication.h"
#include "NebulaDeviceTestLogic/testcase.h"
#include "NebulaDeviceTestLogic/testrunner.h"

namespace
{
class InfrastructureTest : public Test::TestCase
{
    __DeclareClass(InfrastructureTest);
public:
    virtual void Run()
    {
        this->Verify(true);
        this->Verify(false);
    }
};

__ImplementClass(InfrastructureTest, 'TBTS', Test::TestCase);
}

int main()
{
    App::ConsoleApplication application;
    if (!application.Open())
    {
        return 1;
    }

    Ptr<Test::TestRunner> runner = Test::TestRunner::Create();
    Ptr<InfrastructureTest> test = InfrastructureTest::Create();
    runner->AttachTestCase(test);
    runner->Run();

    const int result = (test->GetNumVerified() == 2 &&
            test->GetNumSucceeded() == 1 &&
            test->GetNumFailed() == 1) ? 0 : 1;
    application.Close();
    return result;
}
