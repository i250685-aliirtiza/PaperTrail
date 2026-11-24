#pragma once
#include <cstddef>
namespace papertrail { template<class T> class RingQueue { public:
/** Constructs an empty circular queue. */ RingQueue(); /** Releases queue storage. */ ~RingQueue(); /** Copies queue order and values. */ RingQueue(const RingQueue&); /** Transfers queue storage. */ RingQueue(RingQueue&&) noexcept; /** Copies queue contents. */ RingQueue& operator=(const RingQueue&); /** Transfers queue contents. */ RingQueue& operator=(RingQueue&&) noexcept; /** Appends without overwriting existing values, growing by doubling. */ void push(const T& value); /** Removes the front value. */ bool pop(T& output); /** Reads an indexed value from the front. */ const T& get(std::size_t index) const; /** Returns item count. */ std::size_t size() const; /** Reports emptiness. */ bool empty() const; /** Removes all values. */ void clear(); /** Exchanges queue ownership. */ void swapWith(RingQueue& other) noexcept; private: T* data_{}; std::size_t size_{}; std::size_t capacity_{}; std::size_t front_{}; }; }


