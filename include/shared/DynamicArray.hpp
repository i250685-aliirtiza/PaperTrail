#pragma once
#include <cstddef>
#include <utility>
namespace papertrail {
template<class T> class DynamicArray { public:
/** Constructs an empty manually managed array. */ DynamicArray();
/** Releases owned elements and storage. */ ~DynamicArray();
/** Deep-copies another array. */ DynamicArray(const DynamicArray&);
/** Takes ownership of another array's storage. */ DynamicArray(DynamicArray&&) noexcept;
/** Replaces this array with a deep copy. */ DynamicArray& operator=(const DynamicArray&);
/** Takes ownership of another array's storage. */ DynamicArray& operator=(DynamicArray&&) noexcept;
/** Returns the number of elements. */ std::size_t size() const;
/** Returns allocated capacity. */ std::size_t capacity() const;
/** Reports whether the array is empty. */ bool empty() const;
/** Returns an element by index, with invalid indexes rejected by the contract. */ T& get(std::size_t index);
/** Returns a const element by index. */ const T& get(std::size_t index) const;
/** Indexes an element without changing ownership. */ T& operator[](std::size_t index);
/** Appends an element, doubling capacity when full. */ void pushBack(const T& value);
/** Removes the last element and reports failure when empty. */ bool popBack(T& output);
/** Ensures at least the requested capacity. */ void reserve(std::size_t requested);
/** Destroys all elements while retaining storage. */ void clear();
/** Exchanges complete ownership with another array. */ void swapWith(DynamicArray& other) noexcept;
private: T* data_{}; std::size_t size_{}; std::size_t capacity_{}; };
}


