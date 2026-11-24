#pragma once
#include "../shared/Types.hpp"
namespace papertrail { class Tokenizer { public: /** Tokenizes one line into caller storage. */ static StatusCode tokenizeLine(const char* line,char** output,std::size_t capacity,std::size_t& count); /** Tokenizes a complete document stream. */ static StatusCode tokenizeDocument(const char* const* lines,std::size_t lineCount,char** output,std::size_t capacity,std::size_t& count); /** Lowercases and validates one ASCII token. */ static bool normalize(const char* input,char* output,std::size_t capacity); /** Extracts unique tokens while preserving first occurrence order. */ static StatusCode uniqueTokens(char** tokens,std::size_t count,std::size_t& uniqueCount); };
}
using namespace papertrail;
