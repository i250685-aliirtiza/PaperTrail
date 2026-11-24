#pragma once
#include <cstdint>
#include <cstddef>
#include <string>
namespace papertrail {
using FileID=std::uint64_t; using LineID=std::uint64_t; using CommitID=std::uint64_t; using Tick=std::uint64_t;
enum class StatusCode { Success, NoOp, InvalidArgument, NotFound, AlreadyExists, Rejected, Conflict, Aborted, OutsideHistory, CapacityExceeded, InternalError };
enum class OperationType { InsertLine, DeleteLine, EditLine };
enum class ConflictChoice { Keep, Take, Abort };
enum class ConflictKind { EditDelete, DeleteEdit, EditEdit };
enum class EntryType { Document, Folder };
enum class SortKey { Name, Modified, Size, Extension };
enum class SortDirection { Ascending, Descending };
struct LineData { LineID id{}; std::string text; std::string author; };
struct Posting { FileID file{}; LineID line{}; };
struct GraphEdge { FileID other{}; std::uint32_t occurrences{}; };
struct ExplorerResult { StatusCode status{}; FileID file{}; };
struct EditResult { StatusCode status{}; LineID line{}; std::string warning; };
struct SaveResult { StatusCode status{}; CommitID commit{}; };
struct DiscardResult { StatusCode status{}; std::uint32_t count{}; };
struct HistoryEntry { CommitID commit{}; Tick tick{}; CommitID mergedParent{}; };
struct LogResult { StatusCode status{}; HistoryEntry* entries{}; std::size_t count{}; };
struct ViewResult { StatusCode status{}; LineData* lines{}; std::size_t count{}; };
struct StatusResult { StatusCode status{}; CommitID head{}; std::size_t staged{}; };
struct ForkResult { StatusCode status{}; FileID file{}; };
struct CommonAncestorResult { StatusCode status{}; CommitID commit{}; };
struct MergeResult { StatusCode status{}; std::size_t applied{}, skipped{}, kept{}, noted{}; };
struct SearchHit { FileID file{}; LineID line{}; std::size_t position{}; };
struct SearchResult { StatusCode status{}; SearchHit* hits{}; std::size_t count{}; };
struct GraphResult { StatusCode status{}; GraphEdge* edges{}; std::size_t count{}; };
struct SimilarityResult { StatusCode status{}; FileID first{}, second{}; double score{}; };
struct DiagnosticResult { StatusCode status{}; std::string details; };
}
using namespace papertrail;



