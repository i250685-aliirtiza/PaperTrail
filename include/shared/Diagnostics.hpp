#pragma once
#include "Results.hpp"
namespace papertrail { class Workspace; class VersionControl; class ContentServices; class CommandShell;
class InvariantChecker { public: InvariantChecker(Workspace&,VersionControl&,ContentServices&); DiagnosticResult checkAll() const; };
class Fuzzer { public: Fuzzer(); FuzzResult run(std::uint64_t seed,std::size_t count,CommandShell&,InvariantChecker&) const; };
}
