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

function compilepp() {
  "$CXX" -masm=intel -g -O0 -Wall -Wpedantic --std=c++20 $@
}

function compilec() {
  "$CC" -masm=intel -g -O0 -Wall -Wpedantic --std=c11 $@
}

if [[ "$CC" != "NONE" ]]; then
  echo -e "C++ compiler autodetected as $(${CXX} --version | head -n 1)\nC compiler autodetected as $(${CC} --version | head -n 1)"
  echo -e "Use \"compilepp\" to compile a C++ program and \"compilec\" to compile a C program"
else
  echo -e "No valid C/C++ compilers found"
fi

