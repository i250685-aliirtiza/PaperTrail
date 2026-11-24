#pragma once
#include "../shared/Types.hpp"
#include "../shared/Results.hpp"
namespace papertrail { class OrderStatisticAVL { public:
/** Constructs an empty line tree. */ OrderStatisticAVL(); /** Releases nodes and lookup map. */ ~OrderStatisticAVL(); /** Returns line count. */ std::size_t lineCount() const; /** Selects one-based position. */ bool getByPosition(std::size_t position,LineData& output) const; /** Looks up a LineID. */ bool getById(LineID id,LineData& output) const; /** Returns one-based rank. */ bool getPosition(LineID id,std::size_t& output) const; /** Finds the preceding LineID, or zero. */ bool getPreviousId(LineID id,LineID& output) const; /** Inserts after an anchor, with zero meaning beginning. */ StatusCode insertAfter(LineID anchor,const LineData& line); /** Edits text and author, returning old data. */ StatusCode editById(LineID id,const char* text,const char* author,LineData& oldLine); /** Erases a line and returns predecessor. */ StatusCode eraseById(LineID id,LineData& removed,LineID& previous); /** Deep-copies another tree preserving IDs. */ StatusCode cloneFrom(const OrderStatisticAVL& source); /** Atomically exchanges trees. */ void swapWith(OrderStatisticAVL& other) noexcept; /** Removes every line. */ void clear(); /** Checks AVL and map invariants. */ DiagnosticResult validateInvariants() const; private: struct Node; Node* root_{}; };
}


