#pragma once
#include <string>
#include "../shared/Types.hpp"
#include "../shared/DynamicArray.hpp"
namespace papertrail { class Tokenizer { public: static StatusCode tokenizeLine(const char* line,DynamicArray<std::string>& output); static StatusCode tokenizeDocument(const DynamicArray<std::string>& lines,DynamicArray<std::string>& output); static bool normalize(const char* input,std::string& output); static StatusCode uniqueTokens(const DynamicArray<std::string>& input,DynamicArray<std::string>& output); }; }
