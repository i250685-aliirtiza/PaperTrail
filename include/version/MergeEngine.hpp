#pragma once
#include "Operation.hpp"
#include "CommitDAG.hpp"
#include "../workspace/OrderStatisticAVL.hpp"
namespace papertrail { struct ConflictInfo { LineID line{}; ConflictKind kind{}; bool incomingDeleted{}; const char* currentText{}; const char* incomingText{}; }; class ConflictResolver { public: /** Chooses how a merge conflict is resolved. */ virtual ConflictChoice resolve(const ConflictInfo& conflict)=0; protected: ~ConflictResolver(); }; class MergeEngine { public: /** Merges incoming saved history into target using atomic publication. */ MergeResult merge(CommitDAG&,OrderStatisticAVL&,const Commit*,const Commit*,ConflictResolver&,bool targetBinned,bool incomingBinned); /** Performs merge preflight checks. */ StatusCode preflight(const Commit* target,const Commit* incoming,bool targetStaged,bool incomingStaged) const; };
}
using namespace papertrail;

