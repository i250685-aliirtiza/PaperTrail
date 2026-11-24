#pragma once
#include <cstddef>
#include "Operation.hpp"
#include "../shared/RingQueue.hpp"
#include "../shared/HashMap.hpp"
#include "../search/BloomFilter.hpp"
#include "../shared/Results.hpp"
namespace papertrail {
struct Commit { CommitID id{}; Commit* parent1{}; Commit* parent2{}; Tick tick{}; std::size_t depth{}; RingQueue<Operation> operations; BloomFilter bloom; std::size_t references{}; };
class CommitDAG {
public:
    CommitDAG(); ~CommitDAG(); CommitDAG(const CommitDAG&) = delete; CommitDAG& operator=(const CommitDAG&) = delete; CommitDAG(CommitDAG&&) = delete; CommitDAG& operator=(CommitDAG&&) = delete;
    Commit* prepareRootCommit(Tick tick);
    Commit* prepareNormalCommit(Commit* parent,const RingQueue<Operation>& operations,Tick tick);
    Commit* prepareMergeCommit(Commit* firstParent,Commit* secondParent,const RingQueue<Operation>& operations,Tick tick);
    StatusCode registerPreparedCommit(Commit* prepared);
    void discardPreparedCommit(Commit* prepared) noexcept;
    Commit* lookup(CommitID id) const;
    void acquireHead(Commit* commit); void releaseHead(Commit* commit);
    bool isAncestor(const Commit* ancestor,const Commit* descendant) const;
    CommonAncestorResult commonAncestor(const Commit* first,const Commit* second) const;
    DiagnosticResult validate() const;
private:
    HashMap<CommitID,Commit*> commits_;
};
}
