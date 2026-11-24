#pragma once
#include "../shared/Types.hpp"
#include "../shared/Results.hpp"
namespace papertrail { class Similarity { public: SimilarityListResult findSimilarPairs(std::size_t limit) const; double compare(FileID first,FileID second) const; }; }
