cmake_minimum_required(VERSION 3.16)
project(teme-info)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)

set(IS_DEBUG_BUILD CMAKE_BUILD_TYPE STREQUAL "Debug")
if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(LINUX TRUE)
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
    add_compile_options(-masm=intel)
    add_compile_options(-Wall -Wextra -Wconversion -Wpedantic)
    if (${IS_DEBUG_BUILD})
        add_link_options(-rdynamic)
    endif ()
endif ()

file(WRITE ${CMAKE_BINARY_DIR}/.gitignore "*")

include_directories("${CMAKE_SOURCE_DIR}/include")
add_subdirectory("${CMAKE_SOURCE_DIR}/src")
add_subdirectory("${CMAKE_SOURCE_DIR}/playground")