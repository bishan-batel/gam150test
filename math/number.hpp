#pragma once

#include <cstddef>
#include <cstdint>

/**
 * 8 Bit Signed Integer
*/
using i8 = std::int8_t;

/**
 * 16 Bit Signed Integer
*/
using i16 = std::int16_t;

/**
 * 32 Bit Signed Integer
*/
using i32 = std::int32_t;

/**
 * 64 Bit Signed Integer
*/
using i64 = std::int64_t;

/**
 * Maximum possible bit Signed Integer
*/
using imax = std::uintmax_t;

/**
 * 8 bit unsigned integer
*/
using u8 = std::uint8_t;

/**
 * 16 bit unsigned integer
*/
using u16 = std::uint16_t;

/**
 * 32 bit unsigned integer
*/
using u32 = std::uint32_t;

/**
 * 64 bit unsigned integer
*/
using u64 = std::uint64_t;

/**
 * Generic unsigned memory size
*/
using usize = std::size_t;

/**
 * Maximum possible bit unsigned Integer
*/
using umax = std::uintmax_t;

/**
 * 32 bit floating point number
 */
using f32 = float;

/**
 * 64 bit floating point number
 */
using f64 = double;

namespace gl {
  using id = u32;
}
