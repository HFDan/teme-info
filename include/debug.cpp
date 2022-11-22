#include <debug.hpp>
#ifndef _WIN32
#include <cxxabi.h>
#include <execinfo.h>
#endif

[[noreturn]]
void term_handler() noexcept {
    std::cerr << "Error encountered, terminating...\n";
    printBacktrace();
    abort();
}

void printBacktrace() {
    #ifndef _WIN32
    void* arr[20];
    char** strs;

    int sz = backtrace(arr, 20);
    strs = backtrace_symbols(arr, sz);

    if (strs != nullptr) {
        fprintf(stderr, "Traceback (most recent call first):\n");
        for (decltype(sz) i = 1; i < sz; i++) {
            char *begin_name = nullptr;
            char *begin_offset = nullptr;
            char *end_offset = nullptr;

            for (char* p = strs[i]; *p; ++p) {

                if (*p == '(')
                    begin_name = p;
                else if (*p == '+')
                    begin_offset = p;
                else if (*p == ')' && begin_offset) {
                    end_offset = p;
                    break;
                }
            }

            if (begin_name && begin_offset && end_offset && begin_name < begin_offset) {
                *begin_name++ = '\0';
                *begin_offset++ = '\0';
                *end_offset = '\0';

                int status;
                char* ret = abi::__cxa_demangle(begin_name, nullptr, nullptr, &status);
                if (status == 0) {
                    fprintf(stderr, "[%i] %s : %s+%s\n", i, strs[i], ret, begin_offset);
                } else {
                    fprintf(stderr, "[%i] %s : %s()+%s\n", i, strs[i], begin_name, begin_offset);
                }
                delete[] ret;

            } else {
                fprintf(stderr, "[%i] %s\n", i, strs[i]);
            }
        }
    }
    
    delete[] strs;
    #endif
}