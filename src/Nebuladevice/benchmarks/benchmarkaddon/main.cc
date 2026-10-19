//------------------------------------------------------------------------------
//  runbenchmarks.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/core/coreserver.h"
#include "Nebuladevice/foundation/core/sysfunc.h"
#include "Nebuladevice/benchmarks/benchmarkbase/benchmarkrunner.h"
#include "Nebuladevice/foundation/io/ioserver.h"
#include "Nebuladevice/foundation/io/filestream.h"

#include "Nebuladevice/benchmarks/benchmarkaddon/databaseinsert.h"
#include "Nebuladevice/benchmarks/benchmarkaddon/databasequery.h"

using namespace Core;
using namespace Benchmarking;

void __cdecl
main()
{
    // create Nebula3 runtime
    Ptr<CoreServer> coreServer = CoreServer::Create();
    coreServer->SetAppName(Util::StringAtom("Nebula3 Benchmark Runner"));
    coreServer->Open();

    Ptr<IO::IoServer> ioServer = IO::IoServer::Create();    

    // setup and run benchmarks
    Ptr<BenchmarkRunner> runner = BenchmarkRunner::Create();    
    runner->AttachBenchmark(DatabaseInsert::Create());
    runner->AttachBenchmark(DatabaseQuery::Create());
    runner->Run();
    
    // shutdown Nebula3 runtime
    runner = 0;
    ioServer = 0;
    coreServer->Close();
    coreServer = 0;
    SysFunc::Exit(0);
}
