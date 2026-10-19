#pragma once

#if defined(_MSC_VER) || defined(__XBOX360__)
#include <intrin.h>
#define NEBULA_WRITE_BARRIER() _WriteBarrier()
#define NEBULA_READ_WRITE_BARRIER() _ReadWriteBarrier()
#else
#include <atomic>

#define NEBULA_WRITE_BARRIER() \
    std::atomic_thread_fence(std::memory_order_seq_cst)
#define NEBULA_READ_WRITE_BARRIER() \
    std::atomic_thread_fence(std::memory_order_seq_cst)
#endif
