project(SHMO)
cmake_minimum_required(VERSION 3.13)

set(PROJECT_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})
find_package(PythonLibs REQUIRED)

set(CMAKE_BUILD_TYPE Debug)
add_subdirectory(src)
add_subdirectory(test)
