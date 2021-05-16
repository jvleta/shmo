project(SHMO)
cmake_minimum_required(VERSION 3.13)

set(SOURCES main.cpp shmodata.cpp shmosolver.cpp)

add_executable(shmo ${SOURCES})
target_link_libraries(shmo python3.8)
target_include_directories(shmo PUBLIC /usr/include/python3.8)
