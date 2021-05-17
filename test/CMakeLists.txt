set(HEADERS
    ${PROJECT_ROOT_DIR}/src/shmosolver.h
)
set(SOURCES main.cpp)

add_executable(test_shmo ${SOURCES})
target_link_libraries(test_shmo shmocore gtest pthread)
target_include_directories(test_shmo PUBLIC ${PROJECT_ROOT_DIR}/src)
