#pragma once
#include "../shared/Types.hpp"
namespace papertrail { template<class T,class Compare> class MinHeap { public: /** Constructs an empty bounded heap. */ explicit MinHeap(std::size_t limit=0); /** Offers a value under top-k policy. */ bool offer(const T&,Compare); /** Copies minimum value. */ bool minimum(T&) const; /** Removes minimum. */ bool removeMinimum(T&); /** Replaces minimum and restores heap order. */ bool replaceMinimum(const T&,Compare); /** Returns count. */ std::size_t size() const; /** Reports emptiness. */ bool empty() const; /** Clears values. */ void clear(); private: T* values_{}; std::size_t size_{},limit_{}; };
}
using namespace papertrail;
