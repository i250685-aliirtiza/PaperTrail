#pragma once
#include "CommitDAG.hpp"
#include "../workspace/OrderStatisticAVL.hpp"
namespace papertrail { class History { public: /** Builds newest-first first-parent log entries. */ LogResult getLog(const Commit* head) const; /** Tests first-parent membership. */ bool isOnFirstParentChain(const Commit* head,CommitID commit) const; /** Reconstructs a historical commit into a separate tree. */ ViewResult viewCommit(const Commit* head,CommitID commit,OrderStatisticAVL& output) const; private: void* implementation_{}; };
}
using namespace papertrail;
