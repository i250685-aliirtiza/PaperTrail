#pragma once
#include <cstddef>
namespace papertrail {
class BloomFilter {
public:
    explicit BloomFilter(std::size_t bitCount=32768,std::size_t hashCount=3);
    ~BloomFilter();
    BloomFilter(const BloomFilter& other);
    BloomFilter& operator=(const BloomFilter& other);
    BloomFilter(BloomFilter&& other) noexcept;
    BloomFilter& operator=(BloomFilter&& other) noexcept;
    void add(const char* token);
    bool possiblyContains(const char* token) const;
    void copyFrom(const BloomFilter& other);
    void unionWith(const BloomFilter& other);
    void clear();
    std::size_t bitCount() const;
    std::size_t hashCount() const;
private:
    unsigned char* bits_{}; std::size_t bitCount_{}; std::size_t hashCount_{};
};
}
