cmake_minimum_required(VERSION 3.16)
project(teme-info)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)
add_compile_options(-masm=intel)
add_compile_options(-Wall -Wextra -Wconversion -Wpedantic)

set(IS_DEBUG_BUILD CMAKE_BUILD_TYPE STREQUAL "Debug")

if (${IS_DEBUG_BUILD})
    add_link_options(-rdynamic)
endif ()

include_directories("${CMAKE_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_SOURCE_DIR}/src")
add_subdirectory("${CMAKE_SOURCE_DIR}/playground")