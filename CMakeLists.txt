project(SHMO)
cmake_minimum_required(VERSION 3.13)

set(SOURCES main.cpp shmodata.h shmodata.cpp shmosolver.h shmosolver.cpp matplotlibcpp.h)

find_package(PythonLibs REQUIRED)

set(CMAKE_BUILD_TYPE Debug)
add_executable(shmo ${SOURCES})
target_link_libraries(shmo ${PYTHON_LIBRARY})
target_include_directories(shmo PUBLIC ${PYTHON_INCLUDE_DIRS})
