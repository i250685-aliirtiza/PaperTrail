#include"../../include/shared/Hashing.hpp"

using namespace std;
//guys you would be witnessing static_cast rather mod the reason is 
//the static casting automatically works as mod
// with 2^32 as we have 64 bit number it overflows
// and results as the output after taking mod with 2^3
namespace papertrail {

    uint32_t hashId(uint64_t id) {
        return static_cast<uint32_t>(id* 2654435761u);   
     
    }

    uint32_t fnv1a32(const string& text) {
        uint64_t h = 2166136261u;
        for (size_t i = 0; i < text.size(); ++i) {
            h ^= static_cast<unsigned char>(text[i]);
            h *= 16777619u;
        }
        return static_cast<uint32_t>(h);
    }

    uint32_t djb2(const string& text) {
        uint64_t h = 5381u;
        for (size_t i = 0; i < text.size(); ++i) {
            h = h * 33u + static_cast<unsigned char>(text[i]);
        }
        return static_cast<uint32_t>(h);
    }

    size_t bloomPosition(uint32_t h1, uint32_t h2, size_t i, size_t m) {
        uint64_t step = static_cast<uint64_t>(h2 | 1u);
        uint64_t pos = (static_cast<uint64_t>(h1) + static_cast<uint64_t>(i) * step) % m;
        return static_cast<size_t>(pos);
    }

} 