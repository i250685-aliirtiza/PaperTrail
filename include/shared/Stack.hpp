#pragma once
#include "DynamicArray.hpp"
namespace papertrail { template<class T> class Stack { public: /** Pushes a value. */ void push(const T& value); /** Pops the newest value. */ bool pop(T& output); /** Copies the newest value without removal. */ bool top(T& output) const; /** Returns item count. */ std::size_t size() const; /** Reports emptiness. */ bool empty() const; /** Removes all values. */ void clear(); private: DynamicArray<T> values_; }; }
using namespace papertrail;
