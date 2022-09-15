export DATE=$(date '+%Y-%b-%d')

function compile() {
  clang++ -masm=intel -g -O0 -Wall -Wpedantic --std=c++20 $@
}

echo "Use \"compile\" to compile a c++ program"
