#ifdef __cplusplus
    #error "C++ compiler used for C."
#endif

#if defined(__18CXX)
#define VOID_MAIN
#endif
#if defined(__CLASSIC_C__)
#define const
#define volatile
#endif

#include <stdio.h>

#ifdef ID_VOID_MAIN
void main() {}
#else
#if defined(__CLASSIC_C__)
int main(argc, argv) int argc; char** argv;
#else
int main(int argc, char** argv)
#endif
{
    printf("This is a test C program\n");
    return 0;
}
#endif
