#pragma once
#include <cstddef>
#include <cstdint>
#include <string>

namespace papertrail {

std::uint32_t hashId(std::uint64_t id);
std::uint32_t fnv1a32(const std::string& text);
std::uint32_t djb2(const std::string& text);
std::size_t bloomPosition(std::uint32_t h1, std::uint32_t h2, std::size_t i, std::size_t m);

inline std::uint32_t hashKey(std::uint32_t key) { return hashId(key); }
inline std::uint32_t hashKey(std::uint64_t key) { return hashId(key); }
inline std::uint32_t hashKey(int key) { return hashId(static_cast<std::uint64_t>(key)); }
inline std::uint32_t hashKey(const std::string& key) { return fnv1a32(key); }

} // namespace papertrail