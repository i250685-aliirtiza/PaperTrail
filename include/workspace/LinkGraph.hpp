#pragma once
#include "../shared/Types.hpp"
#include "../shared/Results.hpp"
namespace papertrail { class LinkGraph { public: /** Constructs an empty saved-link graph. */ LinkGraph(); /** Releases adjacency lists. */ ~LinkGraph(); LinkGraph(const LinkGraph&) = delete; LinkGraph& operator=(const LinkGraph&) = delete; LinkGraph(LinkGraph&&) = delete; LinkGraph& operator=(LinkGraph&&) = delete; /** Synchronizes one document's saved outgoing links atomically. */ StatusCode synchronizeSavedLinks(FileID source,const char* folder,const char* text); /** Returns outgoing links. */ GraphResult outgoing(FileID source) const; /** Returns backlinks. */ GraphResult backlinks(FileID target) const; /** Performs bounded BFS over related documents. */ GraphResult related(FileID source,std::size_t depth) const; /** Lists unresolved links. */ GraphResult broken() const; /** Lists live documents with no incoming links. */ GraphResult orphans() const; /** Registers a newly created or forked document. */ StatusCode onDocumentCreated(FileID file); /** Updates bin visibility. */ StatusCode onDocumentBinned(FileID file,bool binned); /** Removes permanent-deletion edges. */ StatusCode onDocumentDeleted(FileID file); /** Validates adjacency symmetry and counts. */ DiagnosticResult validate() const; private: struct Edge; Edge* edges_{}; };
}


