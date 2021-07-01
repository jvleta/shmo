project(SHMO)
cmake_minimum_required(VERSION 3.13)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build.emscripten)
set(CMAKE_TOOLCHAIN_FILE /home/jimmy/Desktop/code/emsdk/)

set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(src)
