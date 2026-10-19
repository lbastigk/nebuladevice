//------------------------------------------------------------------------------
//  runbenchmarks.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "Nebuladevice/foundation/stdneb.h"
#include "Nebuladevice/foundation/core/coreserver.h"
#include "Nebuladevice/foundation/core/sysfunc.h"
#include "Nebuladevice/benchmarks/benchmarkbase/benchmarkrunner.h"

#include "Nebuladevice/benchmarks/benchmarkfoundation/createobjects.h"
#include "Nebuladevice/benchmarks/benchmarkfoundation/createobjectsbyfourcc.h"
#include "Nebuladevice/benchmarks/benchmarkfoundation/createobjectsbyclassname.h"
#include "Nebuladevice/benchmarks/benchmarkfoundation/float4math.h"
#include "Nebuladevice/benchmarks/benchmarkfoundation/matrix44inverse.h"
#include "Nebuladevice/benchmarks/benchmarkfoundation/matrix44multiply.h"
#include "Nebuladevice/benchmarks/benchmarkfoundation/mempoolbenchmark.h"

using namespace Core;
using namespace Benchmarking;

void __cdecl
main()
{
    // create Nebula3 runtime
    Ptr<CoreServer> coreServer = CoreServer::Create();
    coreServer->SetAppName(Util::StringAtom("Nebula3 Benchmark Runner"));
    coreServer->Open();

    // setup and run benchmarks
    Ptr<BenchmarkRunner> runner = BenchmarkRunner::Create();    
//    runner->AttachBenchmark(Matrix44Multiply::Create());
//    runner->AttachBenchmark(Matrix44Inverse::Create());
//    runner->AttachBenchmark(Float4Math::Create());
    runner->AttachBenchmark(MemPoolBenchmark::Create());
    runner->AttachBenchmark(CreateObjects::Create());
    runner->AttachBenchmark(CreateObjectsByFourCC::Create());
    runner->AttachBenchmark(CreateObjectsByClassName::Create());
    runner->Run();
    
    // shutdown Nebula3 runtime
    runner = 0;
    coreServer->Close();
    coreServer = 0;
    SysFunc::Exit(0);
}
