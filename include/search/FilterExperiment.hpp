#pragma once
#include "../shared/Results.hpp"
namespace papertrail { class FilterExperiment { public: /** Measures plain Bloom false positives against theoretical rate. */ FilterExperimentResult runPlain(std::size_t bits,std::size_t hashes,std::size_t inserts,std::size_t probes,std::uint64_t seed) const; /** Measures counting Bloom false positives and saturation. */ FilterExperimentResult runCounting(std::size_t counters,std::size_t hashes,std::size_t inserts,std::size_t probes,std::uint64_t seed) const; };
}


