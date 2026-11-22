# Architecture

PaperTrail is a single-process, single-threaded, in-memory console program. The repository is organized into shared foundations, version control, search and analysis, and workspace and document modules.

## Project constraints

- No STL containers, STL algorithms, or smart pointers.
- std::string and iostream are permitted.
- Manual memory management.
- Maximum 50 documents and 5,000 lines per document.
- Deterministic IDs and behavior.
- Exact required console output.
- Zero live allocations at termination.
- No warnings or errors in final compilation.
- The official instructor project statement governs requirements.

Working document state, saved commit history, and saved derived views remain architecturally distinct.
