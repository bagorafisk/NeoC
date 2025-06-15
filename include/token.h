#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <variant>
#include <optional>
#include <vector>
#include <cstdint>
#include <cstddef>

struct Token;

using LiteralValue = std::variant<
    int8_t,              // Signed 8-bit integer
    int16_t,             // Signed 16-bit integer
    int32_t,             // Signed 32-bit integer
    int64_t,             // Signed 64-bit integer

    uint8_t,             // Unsigned 8-bit integer
    uint16_t,            // Unsigned 16-bit integer
    uint32_t,            // Unsigned 32-bit integer
    uint64_t,            // Unsigned 64-bit integer

    float,               // 32-bit floating point
    double,              // 64-bit floating point

    long double,         // Extended precision float

    bool,                // Boolean value
    char,                // Character
    std::string,         // String literals and multi-character values
    std::nullptr_t,      // Null pointer literal

    std::vector<LiteralValue> // Lists/arrays of literals
>;

#endif
