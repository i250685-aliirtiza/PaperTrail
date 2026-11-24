#pragma once
#include "../shared/Results.hpp"
namespace papertrail { class Blocklist { public: StatusCode blockWord(const char* word); StatusCode unblockWord(const char* word); bool isBlocked(const char* word) const; BlocklistResult checkLine(const char* text) const; WordListResult getBlockedWords() const; std::size_t getAvoidedExactLookups() const; DiagnosticResult validate() const; }; }
