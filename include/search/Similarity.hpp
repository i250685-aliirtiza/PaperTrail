#pragma once
#include "../shared/Types.hpp"
namespace papertrail { class Similarity { public: /** Finds deterministic top-k similar live document pairs. */ SimilarityResult* findSimilarPairs(std::size_t& count,std::size_t limit) const; /** Returns similarity score for a pair. */ double compare(FileID first,FileID second) const; };
}
using namespace papertrail;
