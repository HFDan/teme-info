#pragma once
#include <cstdint>

typedef uint8_t byte;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;

typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

#ifdef ENABLE_128BIT
typedef __int128 int128;
#endif

#ifndef _WIN32
static inline void nop() { __asm volatile("nop"); }
static inline void int3() { __asm volatile("int3"); }
#else
static inline void nop() {}
static inline void int3() {}
#endif