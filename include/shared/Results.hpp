#pragma once
#include "Types.hpp"
#include "DynamicArray.hpp"
namespace papertrail {
struct ExplorerResult { StatusCode status{}; FileID file{}; };
struct ExplorerEntry { EntryType type{}; FileID file{}; FolderID folder{}; std::string name; std::size_t lines{}; std::size_t size{}; Tick modified{}; bool starred{}; bool binned{}; };
struct ExplorerListResult { StatusCode status{}; DynamicArray<ExplorerEntry> entries; };
struct PropertiesResult { StatusCode status{}; FileID file{}; std::string name; std::size_t bytes{}; std::size_t lines{}; Tick created{}; Tick modified{}; bool starred{}; bool binned{}; };
struct BinEntry { BinID bin{}; EntryType type{}; std::string name; std::string originalParentPath; std::size_t documentCount{}; };
struct BinResult { StatusCode status{}; BinID bin{}; std::string resultingPath; bool originalParentMissing{}; bool nameCollisionResolved{}; };
struct BinListResult { StatusCode status{}; DynamicArray<BinEntry> entries; };
struct EmptyBinResult { StatusCode status{}; std::size_t itemsDeleted{}; std::size_t documentsFreed{}; };
struct EditResult { StatusCode status{}; LineID line{}; DynamicArray<std::string> blockedWords; };
struct SaveResult { StatusCode status{}; CommitID commit{}; std::size_t operationCount{}; };
struct DiscardResult { StatusCode status{}; std::size_t operationCount{}; };
struct HistoryEntry { CommitID commit{}; Tick tick{}; std::size_t depth{}; std::size_t operationCount{}; CommitID mergedParent{}; bool isRoot{}; DynamicArray<std::string> authors; };
struct LogResult { StatusCode status{}; DynamicArray<HistoryEntry> entries; };
struct ViewResult { StatusCode status{}; DynamicArray<LineData> lines; };
struct StatusResult { StatusCode status{}; CommitID head{}; std::size_t lines{}; std::size_t staged{}; std::size_t linksOut{}; std::size_t backlinks{}; std::size_t blockedLines{}; };
struct ForkResult { StatusCode status{}; FileID file{}; CommitID inheritedHead{}; };
struct CommonAncestorResult { StatusCode status{}; CommitID commit{}; std::size_t depth{}; std::size_t firstAhead{}; std::size_t secondAhead{}; };
struct MergeResult { StatusCode status{}; CommitID commit{}; std::size_t applied{}; std::size_t skipped{}; std::size_t kept{}; std::size_t noted{}; DynamicArray<MissingAnchorNote> notes; };
struct SearchHit { FileID file{}; LineID line{}; std::size_t position{}; std::string documentName; std::string author; std::string text; };
struct SearchResult { StatusCode status{}; DynamicArray<SearchHit> hits; std::size_t documentsMatched{}; std::size_t bloomPassed{}; std::size_t bloomTotal{}; bool prefixQuery{}; };
struct PostingResult { StatusCode status{}; DynamicArray<Posting> postings; };
struct GraphResult { StatusCode status{}; DynamicArray<GraphRecord> records; };
struct ExpandedLine { std::string text; std::size_t depth{}; bool cycleSkipped{}; bool unresolved{}; };
struct ExpandResult { StatusCode status{}; DynamicArray<ExpandedLine> lines; };
struct SimilarityResult { FileID first{}; FileID second{}; double score{}; CommitID commonAncestor{}; bool forkRelated{}; };
struct SimilarityListResult { StatusCode status{}; DynamicArray<SimilarityResult> pairs; };
struct BlocklistResult { StatusCode status{}; DynamicArray<std::string> matchedWords; std::size_t avoidedLookups{}; };
struct WordListResult { StatusCode status{}; DynamicArray<std::string> words; };
struct FilterExperimentResult { StatusCode status{}; double measuredRate{}; double theoreticalRate{}; std::size_t saturations{}; };
struct DiagnosticResult { StatusCode status{}; std::string details; };
struct FuzzResult { StatusCode status{}; std::size_t commandsRun{}; std::string replayScriptPath; std::string failingCommand; };
}
