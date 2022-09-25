export DATE=$(date '+%Y-%b-%d')

if [[ -f "/bin/clang++" ]]; then
  CXX="/bin/clang++"
  CC="/bin/clang"
elif [[ -f "/bin/g++" ]]; then
  CXX="/bin/g++"
  CC="/bin/gcc"
else
  CXX="NONE"
  CC="NONE"
fi

if [[ -f "/bin/nasm" ]]; then
    ASM="/bin/nasm"
else
    ASM="NONE"
fi

function compile++() {
  "$CXX" -masm=intel -g -O0 -Wall -Wpedantic --std=c++20 $@
}

function compile() {
  "$CC" -masm=intel -g -O0 -Wall -Wpedantic --std=c11 $@
}

function runSanityTests() {
    local SCRIPT=$(realpath "$0")
    local SCRIPTPATH="."

    if [[ -d "./sanitytests" ]]; then
        # C++ sanity test
        local CPPOUT=$("$CXX" -masm=intel -g -O0 -Wall -Wpedantic ${SCRIPTPATH}/sanitytests/c++sanity.cpp -o ${SCRIPTPATH}/sanitytests/c++sanity.out 2>&1) 
        # C sanity test
        local COUT=$("$CC" -masm=intel -g -O0 -Wall -Wpedantic ${SCRIPTPATH}/sanitytests/csanity.c -o ${SCRIPTPATH}/sanitytests/csanity.out 2>&1)
        # ASM sanity test
        if [[ "$ASM" != "NONE" ]]; then
            local ASMOUT=$("$ASM" -felf64 -Wall -g -F dwarf ${SCRIPTPATH}/sanitytests/asmsanity.asm -o ${SCRIPTPATH}/sanitytests/asmsanity.o 2>&1)
            strip --strip-unneeded ${SCRIPTPATH}/sanitytests/asmsanity.o && "$CC" ${SCRIPTPATH}/sanitytests/asmsanity.o -o ${SCRIPTPATH}/sanitytests/asmsanity
        fi

        # CHECKS
        # Currently disabled. C compilers have a wierd bug where they ignore ifdef __cplusplus 
        # if [[ "$(echo ${CPPOUT} | grep -- "C compiler used for C++")" != "" ]]; then
        #     echo "ERROR: A C compiler was used for C++"
        # fi

        if [[ "$(echo ${COUT} | grep -- 'C++ compiler used for C')" != "" ]]; then
            echo "ERROR: A C++ compiler was used for C"
        fi

        if [[ "$(${SCRIPTPATH}/sanitytests/c++sanity.out | grep -- 'This is a test c++ program' )" == "" ]]; then
            echo "ERROR: C++ sanity check failed"
        fi        
        if [[ "$(${SCRIPTPATH}/sanitytests/csanity.out | grep -- 'This is a test C program' )" == "" ]]; then
            echo "ERROR: C sanity check failed"
        fi        
        if [[ "$(${SCRIPTPATH}/sanitytests/asmsanity | grep -- 'This is a test assembly program' )" == "" ]]; then
            echo "ERROR: ASM sanity check failed"
        fi        

        # CLEANUP
        rm ${SCRIPTPATH}/sanitytests/asmsanity.o ${SCRIPTPATH}/sanitytests/asmsanity ${SCRIPTPATH}/sanitytests/c++sanity.out ${SCRIPTPATH}/sanitytests/csanity.out 2>&1 1>/dev/null
    else
        echo "Sanity tests can only be run in the project root"
    fi

}

if [[ "$CC" != "NONE" ]]; then
    echo -e "C++ compiler autodetected as $(${CXX} --version | head -n 1)\nC compiler autodetected as $(${CC} --version | head -n 1)"
    echo -e "Use \"compile++\" to compile a C++ program and \"compile\" to compile a C program"
    if [[ "$1" != "--no-sanity-test" ]]; then
        runSanityTests
    fi
else
    echo -e "No valid C/C++ compilers found"
fi

