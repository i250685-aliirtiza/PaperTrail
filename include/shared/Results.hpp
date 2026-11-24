#pragma once
#include "Types.hpp"
namespace papertrail {
struct ExplorerEntry { EntryType type{}; FileID file{}; const char* name{}; std::size_t size{}; Tick modified{}; bool starred{}, binned{}; };
struct ExplorerListResult { StatusCode status{}; ExplorerEntry* entries{}; std::size_t count{}; };
struct PropertiesResult { StatusCode status{}; FileID file{}; const char* name{}; std::size_t bytes{}, lines{}; Tick created{}, modified{}; bool starred{}, binned{}; };
struct BlocklistResult { StatusCode status{}; std::size_t avoidedLookups{}; };
struct FilterExperimentResult { StatusCode status{}; double measuredRate{}, theoreticalRate{}; std::size_t saturations{}; };
struct FuzzResult { StatusCode status{}; std::size_t commandCount{}; const char* failingCommand{}; };
}
using namespace papertrail;
