#pragma once
#include <cstddef>
namespace papertrail { class BloomFilter { public: /** Constructs a bit filter with byte and hash configuration. */ BloomFilter(std::size_t bytes=4096,std::size_t hashes=3); /** Adds a token or stable key. */ void add(const char* key); /** Tests possible membership. */ bool possiblyContains(const char* key) const; /** Copies filter state. */ void copyFrom(const BloomFilter&); /** ORs another filter. */ void unionWith(const BloomFilter&); /** Clears bits. */ void clear(); /** Returns byte configuration. */ std::size_t byteCount() const; /** Returns hash count. */ std::size_t hashCount() const; private: unsigned char* bits_{}; std::size_t bytes_{},hashes_{}; };
}
using namespace papertrail;
