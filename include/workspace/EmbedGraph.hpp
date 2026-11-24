#pragma once
#include "../shared/Types.hpp"
#include "../shared/Results.hpp"
namespace papertrail { class EmbedGraph { public: StatusCode wouldCreateCycle(FileID source,FileID target) const; StatusCode validateProposed(FileID source,const char* text) const; StatusCode applySavedChanges(FileID source,const char* text); StatusCode onDocumentDeleted(FileID file); ExpandResult expand(FileID file) const; GraphResult broken() const; DiagnosticResult validate() const; private: struct Edge; Edge* edges_{}; }; }
