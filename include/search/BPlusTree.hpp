#pragma once
#include "../shared/Types.hpp"
namespace papertrail { class BPlusTree { public: /** Constructs a B+ tree with compile-time order. */ explicit BPlusTree(std::size_t order=3); /** Releases all nodes. */ ~BPlusTree(); /** Inserts a posting under a token. */ StatusCode insert(const char* key,Posting posting); /** Removes one posting. */ StatusCode remove(const char* key,Posting posting); /** Performs exact lookup. */ SearchResult findExact(const char* key) const; /** Scans keys from lower bound. */ SearchResult scanFrom(const char* key,std::size_t limit) const; /** Traverses linked leaves for prefix matches. */ SearchResult scanPrefix(const char* prefix,std::size_t limit) const; /** Validates occupancy, ordering and leaf links. */ DiagnosticResult validate() const; /** Clears all nodes. */ void clear(); private: void* root_{}; std::size_t order_{}; };
}
using namespace papertrail;
