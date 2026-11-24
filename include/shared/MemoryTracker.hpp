#pragma once
#include <cstddef>
#include <string>
namespace papertrail { class MemoryTracker { public: static std::size_t allocationCount(); static std::size_t freeCount(); static std::size_t liveAllocations(); static std::string finalReport(); static void reset(); }; }


