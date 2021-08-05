include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB_RECURSE SOURCES  *.cpp)
add_executable(rec ${SOURCES})
target_link_libraries(rec m)
