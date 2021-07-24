include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
file(GLOB_RECURSE sources  *.c)
add_executable(rec ${sources})
target_link_libraries(rec m)
