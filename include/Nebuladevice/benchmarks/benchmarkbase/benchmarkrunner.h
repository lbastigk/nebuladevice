#ifndef BENCHMARKING_BENCHMARKRUNNER_H
#define BENCHMARKING_BENCHMARKRUNNER_H
//------------------------------------------------------------------------------
/**
    @class Benchmarking::BenchmarkRunner

    The benchmark runner class which runs all benchmarks.
    
    (C) 2006 Radon Labs GmbH
*/
#include "Nebuladevice/foundation/core/refcounted.h"
#include "Nebuladevice/foundation/core/ptr.h"
#include "Nebuladevice/foundation/util/array.h"
#include "Nebuladevice/benchmarks/benchmarkbase/benchmark.h"

//------------------------------------------------------------------------------
namespace Benchmarking
{
class BenchmarkRunner : public Core::RefCounted
{
    __DeclareClass(BenchmarkRunner);
public:
    /// attach a benchmark
    void AttachBenchmark(Benchmark* b);
    /// run the benchmarks
    void Run();

private:
    Util::Array<Ptr<Benchmark>> benchmarks;
};

} // namespace Benchmark
//------------------------------------------------------------------------------
#endif


