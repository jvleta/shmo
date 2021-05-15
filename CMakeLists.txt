project(SHMO)
cmake_minimum_required(VERSION 3.13)

set(SOURCES main.cpp shmodata.cpp shmosolver.cpp)

add_executable(shmo ${SOURCES})
