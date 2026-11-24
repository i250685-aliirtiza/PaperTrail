#pragma once
#include <cstddef>
namespace papertrail { class MemoryTracker { public: /** Returns global allocation count. */ static std::size_t allocationCount(); /** Returns global free count. */ static std::size_t freeCount(); /** Returns live allocation count. */ static std::size_t liveAllocations(); /** Emits or returns the final diagnostic report. */ static const char* finalReport(); /** Resets diagnostic counters when safe. */ static void reset(); }; }
using namespace papertrail;
