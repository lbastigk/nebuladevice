#pragma once
//------------------------------------------------------------------------------
/**
    @class Test::JobsTestApplication
  
    Test Jobs subsystem.
    
    (C) 2009 Radon Labs GmbH
*/    
#include "Nebuladevice/foundation/app/consoleapplication.h"
#include "Nebuladevice/foundation/jobs/jobsystem.h"
#include "Nebuladevice/foundation/jobs/job.h"
#include "Nebuladevice/foundation/jobs/jobport.h"
#include "Nebuladevice/foundation/io/gamecontentserver.h"

//------------------------------------------------------------------------------
namespace Test
{
class JobsTestApplication : public App::ConsoleApplication
{
public:
    /// constructor
    JobsTestApplication();
    /// destructor
    virtual ~JobsTestApplication();
    /// open the application
    virtual bool Open();
    /// close the application
    virtual void Close();
    /// run the application
    virtual void Run();

private:
    Ptr<Jobs::JobSystem> jobSystem;
    Ptr<Jobs::JobPort> jobPort;
    Ptr<IO::GameContentServer> gameContentServer;
};

} // namespace Test
//------------------------------------------------------------------------------
