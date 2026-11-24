#pragma once
#include "../shared/Types.hpp"
#include "../shared/Results.hpp"
namespace papertrail { class EmbedGraph { public: /** Constructs an empty saved embed graph. */ EmbedGraph(); /** Releases graph storage. */ ~EmbedGraph(); /** Rejects self edges and cycles in a proposed publication. */ StatusCode wouldCreateCycle(FileID source,FileID target) const; /** Validates proposed saved embed edges. */ StatusCode validateProposed(FileID source,const char* text) const; /** Applies saved embed changes atomically. */ StatusCode applySavedChanges(FileID source,const char* text); /** Synchronizes document lifecycle. */ StatusCode onDocumentDeleted(FileID file); /** Expands a document to depth eight using four-space indentation. */ const char* expand(FileID file) const; /** Lists unresolved embeds. */ GraphResult broken() const; /** Validates acyclicity and adjacency consistency. */ DiagnosticResult validate() const; private: struct Edge; Edge* edges_{}; };
}
using namespace papertrail;
