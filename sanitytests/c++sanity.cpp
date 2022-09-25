#ifdef __cplusplus
    #include <iostream>
    int main(int argc, char** argv) {
        std::cout << "This is a test c++ program\n";
        return 0;
    }
#else
    #error "C compiler used for C++."
#endif