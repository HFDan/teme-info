#include <debug.hpp>
#include <boost/core/verbose_terminate_handler.hpp>
#ifndef _WIN32
#include <cxxabi.h>
#include <execinfo.h>
#endif

[[noreturn]]
void term_handler() noexcept {
    std::set_terminate( nullptr );

    try
    {
        throw;
    }
    catch( std::exception const& ex )
    {
        char const * typeid_name = typeid( ex ).name();

        int status = -1;
        #ifndef _WIN32
        char* ret = abi::__cxa_demangle(typeid_name, nullptr, nullptr, &status);
        #else
        char* ret = typeid_name;
        #endif // !_WIN32

        if( ret != nullptr )
        {
            typeid_name = ret;
        }

        std::fprintf( stderr,
            "terminating after throwing an exception:\n\n"
            "\ttype: %s\n"
            "\twhat(): %s\n\n",
            typeid_name,
            ex.what()
        );
        #ifndef _WIN32
        delete[] ret;
        #endif
    }
    catch( ... )
    {
        std::fputs( "terminating after throwing an unknown exception\n", stderr );
    }

    
    std::fflush( stdout );

    printBacktrace();
    std::abort();
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