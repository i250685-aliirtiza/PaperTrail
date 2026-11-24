#pragma once
#include "../shared/Types.hpp"
namespace papertrail { class Blocklist { public: /** Adds a normalized blocked word. */ StatusCode blockWord(const char* word); /** Removes a blocked word. */ StatusCode unblockWord(const char* word); /** Tests exact membership. */ bool isBlocked(const char* word) const; /** Reports whole-token warnings in a line. */ BlocklistResult checkLine(const char* line) const; /** Copies stable alphabetical words. */ StatusCode getBlockedWords(char** output,std::size_t capacity,std::size_t& count) const; /** Returns avoided exact lookups. */ std::size_t getAvoidedExactLookups() const; /** Validates counting Bloom and exact set. */ DiagnosticResult validate() const; };
}
using namespace papertrail;
