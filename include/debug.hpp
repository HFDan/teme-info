#pragma once
#include <iostream>
#include <string_view>

#ifndef _WIN32
#define ASSERT(expr, msg)                                                                           \
    if (!expr) {                                                                                    \
        std::cerr << "[" << __FILE_NAME__ << "@" << __LINE__ << "]:" << __PRETTY_FUNCTION__ << ": " \
                  << "ASSERTION FAILED:" << msg << std::endl;                                       \
    }
#else
#define ASSERT(expr, msg)                                                                   \
    if (!expr) {                                                                            \
        std::cerr << "[" << __FILE_NAME__ << "@" << __LINE__ << "]:" << __FUNCSIG__ << ": " \
                  << "ASSERTION FAILED:" << msg << std::endl;                               \
    }
#endif

inline void debugger() {
#ifndef _WIN32
    asm volatile("int3");
#else
    __asm int 3
#endif
}

void printBacktrace();

[[noreturn]]
void term_handler() noexcept;