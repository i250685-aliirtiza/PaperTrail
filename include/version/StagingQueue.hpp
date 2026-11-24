#pragma once
#include "Operation.hpp"
#include "../shared/RingQueue.hpp"
namespace papertrail { class StagingQueue { public: /** Constructs an empty per-document operation queue. */ StagingQueue(); /** Releases queued operations. */ ~StagingQueue(); /** Appends a reversible operation. */ StatusCode stage(const Operation& operation); /** Reads an operation by staging order. */ bool get(std::size_t index,Operation& output) const; /** Returns staged count. */ std::size_t count() const; /** Reports whether staging is empty. */ bool empty() const; /** Clears all staged operations. */ void clear(); /** Transfers queue ownership. */ void swapWith(StagingQueue& other) noexcept; private: RingQueue<Operation> queue_; };
}
using namespace papertrail;
