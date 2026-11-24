#pragma once
#include <cstddef>
#include "../shared/Types.hpp"
#include "../shared/Results.hpp"
namespace papertrail {
class BPlusTree { public:
    static constexpr std::size_t ORDER=3;
    BPlusTree(); ~BPlusTree();
    StatusCode insert(const char* token,Posting posting);
    StatusCode remove(const char* token,Posting posting);
    PostingResult findExact(const char* token) const;
    PostingResult scanPrefix(const char* prefix) const;
    DiagnosticResult validate() const; void clear();
private: struct Node; Node* root_{};
};
}
