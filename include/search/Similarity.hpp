#pragma once
#include "../shared/Types.hpp"
#include "../shared/Results.hpp"
namespace papertrail { class Workspace; class Similarity { public: explicit Similarity(const Workspace& workspace); SimilarityListResult findSimilarPairs(std::size_t limit) const; double compare(FileID first,FileID second) const; private: const Workspace* workspace_{}; }; }
