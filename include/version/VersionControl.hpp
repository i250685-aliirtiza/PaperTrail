#pragma once
#include "../shared/Results.hpp"
#include "../shared/HashMap.hpp"
#include "CommitDAG.hpp"
#include "StagingQueue.hpp"
namespace papertrail {
class Document; class Workspace; class ContentServices; class ConflictResolver;
class VersionControl {
public:
    VersionControl(); ~VersionControl(); VersionControl(const VersionControl&) = delete; VersionControl& operator=(const VersionControl&) = delete; VersionControl(VersionControl&&) = delete; VersionControl& operator=(VersionControl&&) = delete;
    void bindServices(Workspace& workspace,ContentServices& content);
    EditResult addLine(Document& document,const char* author,const char* text);
    EditResult insertLine(Document& document,std::size_t position,const char* author,const char* text);
    EditResult editLine(Document& document,std::size_t position,const char* author,const char* text);
    EditResult deleteLine(Document& document,std::size_t position,const char* author);
    EditResult embedLine(Document& document,const char* author,const char* targetName);
    SaveResult save(Document& document,Tick tick);
    DiscardResult discard(Document& document);
    bool hasStagedChanges(const Document& document) const;
    LogResult getLog(const Document& document) const;
    ViewResult viewCommit(const Document& document,CommitID commit) const;
    CommitID getHead(const Document& document) const;
    StatusResult getStatus(const Document& document) const;
    ForkResult forkDocument(Document& source,Workspace& workspace,const char* newName,Tick tick);
    CommonAncestorResult findCommonAncestor(const Document& first,const Document& second) const;
    MergeResult mergeDocuments(Document& target,const Document& incoming,ConflictResolver& resolver,Tick tick);
    StatusCode initializeHistory(Document& document,Tick tick);
    StatusCode releaseHistory(Document& document);
    DiagnosticResult validateHistory() const;
    StatusCode resetForFuzz();
private:
    struct VersionState { Commit* head{}; StagingQueue staging; };
    HashMap<FileID,VersionState*> states_; CommitDAG dag_; LineID nextLineID_{1}; Workspace* workspace_{}; ContentServices* content_{};
};
}
