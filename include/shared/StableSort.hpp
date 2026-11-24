#pragma once
#include <cstddef>
namespace papertrail { template<class T,class Compare> class StableSort { public: /** Stable-sorts caller-owned elements using Compare and preserves tie order. */ static void sort(T* values,std::size_t count,Compare compare); }; }
using namespace papertrail;
