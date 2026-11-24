#pragma once
#include "../shared/Types.hpp"
#include "../shared/Results.hpp"
#include "../shared/DynamicArray.hpp"
#include "../shared/RingQueue.hpp"
#include "../version/Operation.hpp"
#include "OrderStatisticAVL.hpp"
namespace papertrail {
class Workspace; class PreparedContentUpdate;
class ContentServices {
public:
    explicit ContentServices(Workspace& workspace); ~ContentServices(); ContentServices(const ContentServices&) = delete; ContentServices& operator=(const ContentServices&) = delete; ContentServices(ContentServices&&) = delete; ContentServices& operator=(ContentServices&&) = delete;
    StatusCode prepareSavedChanges(FileID file,const OrderStatisticAVL& candidateSavedText,const RingQueue<Operation>& committedOperations,PreparedContentUpdate*& prepared);
    StatusCode prepareLifecycle(ContentLifecycleKind kind,const DynamicArray<FileID>& affectedDocuments,FileID forkSource,FileID forkDestination,PreparedContentUpdate*& prepared);
    void publishPrepared(PreparedContentUpdate*& prepared) noexcept;
    void cancelPrepared(PreparedContentUpdate*& prepared) noexcept;
    StatusCode validateEmbedChanges(FileID file,const OrderStatisticAVL& candidateSavedText) const;
    StatusCode wouldCreateEmbedCycle(FileID source,FileID target) const;
    SearchResult search(const char* query,bool prefix) const;
    GraphResult outgoingLinks(FileID source) const;
    GraphResult backlinks(FileID target) const;
    GraphResult related(FileID source,std::size_t depth) const;
    GraphResult brokenLinks() const; GraphResult orphanDocuments() const; GraphResult brokenEmbeds() const;
    ExpandResult expandDocument(FileID file) const;
    SimilarityListResult similarDocuments(std::size_t limit) const;
    StatusCode blockWord(const char* word); StatusCode unblockWord(const char* word);
    WordListResult blockedWords() const; BlocklistResult checkBlockedLine(const char* text) const;
    FilterExperimentResult falsePositiveBloom(std::size_t bits,std::size_t hashes,std::size_t insertions,std::uint64_t seed) const;
    FilterExperimentResult falsePositiveCounting(std::size_t counters,std::size_t hashes,std::size_t insertions,std::uint64_t seed) const;
    DiagnosticResult validateAll() const; StatusCode resetForFuzz();
private: void* implementation_{};
};
}
