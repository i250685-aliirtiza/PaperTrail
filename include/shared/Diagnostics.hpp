#pragma once
#include "../shared/Types.hpp"
#include "../shared/Results.hpp"
namespace papertrail { class InvariantChecker { public: /** Runs all enabled AVL, DAG, index and graph invariants. */ DiagnosticResult checkAll(bool enabled) const; }; class Fuzzer { public: /** Runs deterministic valid command generation and stops on first invariant failure. */ FuzzResult run(std::uint64_t seed,std::size_t count,const char* scriptPath) const; }; }
using namespace papertrail;
