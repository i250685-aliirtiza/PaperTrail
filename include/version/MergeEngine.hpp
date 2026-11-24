#pragma once
#include "Operation.hpp"
#include "CommitDAG.hpp"
#include "../workspace/OrderStatisticAVL.hpp"
namespace papertrail {
struct ConflictInfo { LineID line{}; ConflictKind kind{}; bool currentDeleted{}; bool incomingDeleted{}; const char* currentText{}; const char* incomingText{}; };
class ConflictResolver { public: virtual ~ConflictResolver(); virtual ConflictChoice resolve(const ConflictInfo& conflict)=0; };
class MergeEngine { public: StatusCode prepareMerge(const Commit* target,const Commit* incoming,const Commit* ancestor,const OrderStatisticAVL& targetText,OrderStatisticAVL& candidate,ConflictResolver& resolver,RingQueue<Operation>& applied,MergeResult& outcome) const; };
}
