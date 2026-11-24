# PaperTrail interface contracts

This document defines the declaration-only public boundary. Implementations belong to the owners recorded below and must remain C++17, manually managed, deterministic, and free of STL containers, smart pointers, threads, GUI, database, and network APIs.

## Ownership

- **Ali Irtiza** owns `include/version/*`, `src/version/*`, `RingQueue`, commit references, staging, history, fork, merge, and version lifecycle.
- **Abdul Rehman** owns `include/search/*`, `src/search/*`, `LinkGraph`, `EmbedGraph`, and `HashMap`.
- **Abdullah Khalil** owns `Document`, `FolderTree`, `Workspace`, `CommandShell`, `OrderStatisticAVL`, `DynamicArray`, `Stack`, and `StableSort`.
- Shared ownership covers `Types`, `Results`, `MemoryTracker`, `ContentServices`, `Diagnostics`, command integration, and application checks.

## Shared contracts

`FileID`, `LineID`, `CommitID`, and `Tick` are unsigned 64-bit values. Line IDs are globally unique and never reused. `LineData` carries ID, text, and author. Result records distinguish success, no-op, rejection, conflict, and abort. Business modules return structured results. `CommandShell` owns exact terminal text and logical ticks.

`DynamicArray`, `RingQueue`, `Stack`, `HashMap`, `StableSort`, and `MemoryTracker` are manually managed. Queue growth doubles and never overwrites. Hash chains append new entries and rehash only after load exceeds 0.75. Stable sorting preserves tie order. All destructors release owned allocations.

## Workspace and documents

`Document` owns exactly one authoritative working `OrderStatisticAVL`. AVL positions are one-based and ordered by in-order sequence. LineID lookup is expected O(1), while rank, select, insert, and erase are O(log N). `FolderTree` owns parent-linked N-ary nodes, creation-ordered children, and path lookup. `Workspace` is the explorer facade. New documents receive an empty root commit, `new` does not open them, `cd` closes the current document without discarding staging, and `open` switches without saving. Binning retains history. Permanent deletion releases it.

## Version control

`Operation` records only reversible values and IDs. It never stores positions or node pointers. `StagingQueue` owns one document's unsaved operations. `CommitDAG` owns commits, both parent links, immutable operation queues, depths, filters, and reference counts. `History` traverses first parents for logs and reconstructs views into temporary trees. `MergeEngine` uses both parents, a resolver callback, deep-copy publication, conflict choices, and atomic commit creation. `VersionControl` coordinates editing, save, discard, history, fork, common ancestor, merge, and lifecycle without parsing or printing.

Save publishes staged text, commit state, Bloom filters, indexes, and graphs atomically. Discard replays staged operations newest-first and never changes saved structures. Fork deep-copies saved text while sharing the source HEAD reference. Merge rejects staged, binned, self, unrelated, cyclic, and over-limit operations.

## Search and analysis

`Tokenizer` accepts ASCII letters and digits as token characters. `BPlusTree` is a configurable-order tree with linked leaves and posting ordering by FileID then LineID. `InvertedIndex` indexes saved text only. `BloomFilter` supports commit filters and similarity filters. `LinkGraph` resolves `[[name]]` links relative to the source folder and preserves unresolved targets. `EmbedGraph` validates `{{embed:name}}`, rejects cycles, and expands at depth eight. `Blocklist` warns without blocking edits. `Similarity` uses distinct three-token shingles and bounded top-k ordering. `FilterExperiment` reports measured and theoretical rates.

## Integration and ownership

`ContentServices` is the synchronization boundary between VersionControl, Workspace, indexes, and graphs. It prepares, publishes, or cancels saved changes and handles create, fork, bin, restore, and permanent deletion. Working-text queries (`show`, `authors`, `tac`, similarity, blocklist) read the AVL. Saved queries (search, links, embeds) read published structures. No module exposes AVL nodes, commit internals, or graph storage.

## Commands and diagnostics

`CommandShell` covers explorer, document, version, search/analysis, and diagnostics command groups from the project specification. Every processed command advances the logical tick except blank lines, comments, and merge-answer lines. Breadcrumbs are capped at 40 columns. `InvariantChecker` covers AVL, DAG, B+ tree, postings, Bloom, links, embeds, and blocklist. `Fuzzer` accepts a seed and count, emits a reproducible script, and stops on the first invariant violation.

## Limits and unresolved choices

Implementations enforce at most 50 documents including forks and binned documents, 5,000 lines per document, 200 characters per line, 1–16 ASCII-alphanumeric author names, and 1–32 character file or folder names. Result arrays are caller-owned unless an implementation documents a transfer. Exact user-facing error strings remain a CommandShell responsibility.

## Final frozen signatures and ownership

All public declarations use the `papertrail` namespace. No header imports a namespace into global scope. `Types.hpp` contains only shared aliases, enums, and value records. `Results.hpp` contains every returned result and owns collections through `DynamicArray<T>`. A returned result owns its strings and arrays for its lifetime.

IDs are globally monotonic in their own spaces. `LineID` zero is the insertion anchor for the beginning of a document. File, folder, bin, line, and commit IDs are never reused. Limits remain 50 documents including forks and binned documents, 5,000 lines, 200 characters per line, validated names, and validated authors.

`Operation` owns all historical text and author strings by value. It stores IDs and no positions or AVL pointers. `Commit` owns its immutable published operation queue and Bloom filter. `CommitDAG` owns the registry and uses `HashMap<CommitID, Commit*>`. Preparation produces detached commits. Registration transfers registry ownership and establishes parent references. Document heads add references. Release recursively frees unreachable commits after all child and head references are gone.

`VersionControl` is the sole owner of per-document `VersionState`, including HEAD and staging. Documents contain working text only. Its private mapping is `HashMap<FileID, VersionState*>`, alongside the commit DAG, monotonic LineID counter, Workspace pointer, and ContentServices pointer. Switching, closing, binning, and restoring do not discard version state. Save, discard, fork, and merge use the mandatory caller-provided tick.

`insertLine` accepts a one-based destination position. Position 1 inserts before the current first line, position N+1 appends, and VersionControl translates the position to an anchor LineID before constructing an operation.

## Transaction boundaries

`ContentServices::prepareSavedChanges` receives the candidate saved AVL and committed operation sequence, prepares all postings, Bloom-derived data, link records, and embed validation, and returns an opaque `PreparedContentUpdate`. Preparation may allocate but cannot publish. `publishPrepared` is non-allocating and no-failure. `cancelPrepared` destroys detached state. Both clear the caller pointer. Lifecycle preparation covers every affected document in a folder subtree. Binning changes visibility, restore re-enables it, and permanent deletion purges saved references.

MergeEngine prepares a candidate AVL and applied operation queue. VersionControl owns final ContentServices publication, commit registration, HEAD advancement, and tick assignment. Abort or failed validation leaves target text, staging, HEAD, indexes, graphs, and references unchanged.

## Construction and destruction order

Construct VersionControl first. Construct Workspace with its VersionControl reference. Construct ContentServices with its Workspace reference. Bind ContentServices into Workspace. Bind Workspace and ContentServices into VersionControl. Construct InvariantChecker with the three services. Construct Fuzzer. Construct CommandShell with Workspace, VersionControl, ContentServices, InvariantChecker, and Fuzzer. On shutdown, stop CommandShell, release document heads and VersionStates through VersionControl, destroy ContentServices and Workspace-owned documents, then destroy Workspace and finally VersionControl so CommitDAG is destroyed last among version objects.

## Public method inventory

Shared structures provide manually managed copy/move/destruction, indexed queue access, separate-chaining maps, stable sorting, bounded heaps, Bloom ownership, memory diagnostics, and deterministic invariant/fuzzer entry points. Workspace owns Documents and FolderTree nodes. OrderStatisticAVL owns line nodes and its LineID map. VersionControl owns staging and history. Search owns B+ postings, tokenization, blocklist, similarity, and experiments. LinkGraph and EmbedGraph are saved-text services owned behind ContentServices. CommandShell is the only terminal formatting and conflict-input layer and implements ConflictResolver.

All declaration comments describe the caller, parameters, result, mutation and failure guarantee. Implementations must keep those contracts without adding alternate facades, STL containers, smart pointers, global clocks, or executable logic to these headers.
