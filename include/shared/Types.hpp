#pragma once
#include <cstddef>
#include <cstdint>
#include <string>
namespace papertrail {
using FileID=std::uint64_t; using FolderID=std::uint64_t; using BinID=std::uint64_t; using LineID=std::uint64_t; using CommitID=std::uint64_t; using Tick=std::uint64_t;
enum class OperationType { InsertLine, DeleteLine, EditLine };
enum class ConflictChoice { Keep, Take, Abort };
enum class ConflictKind { EditDelete, DeleteEdit, EditEdit };
enum class EntryType { Document, Folder };
enum class SortKey { Name, Modified, Size, Extension };
enum class SortDirection { Ascending, Descending };
enum class ContentLifecycleKind { Created, Forked, Binned, Restored, PermanentlyDeleted };
enum class StatusCode { Success, NoOp, AlreadyUpToDate, InvalidArgument, InvalidName, InvalidAuthor, InvalidPosition, InvalidText, TextTooLong, NotFound, AlreadyExists, NoOpenDocument, WrongEntryType, StagedChanges, SelfMerge, UnrelatedHistory, OutsideHistory, CapacityExceeded, EmbedCycle, Conflict, Aborted, InternalError };
struct LineData { LineID id{}; std::string text; std::string author; };
struct Posting { FileID file{}; LineID line{}; };
struct GraphEdge { FileID other{}; std::uint32_t occurrences{}; };
struct MissingAnchorNote { LineID line{}; LineID missingAnchor{}; };
struct GraphRecord { FileID source{}; FileID target{}; std::string reference; std::size_t occurrences{}; bool resolved{}; };
}
