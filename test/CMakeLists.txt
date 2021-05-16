set(HEADERS
    ${PROJECT_ROOT_DIR}/src/shmodata.h
    ${PROJECT_ROOT_DIR}/src/shmosolver.h
    ${PROJECT_ROOT_DIR}/src/matplotlibcpp.h
)
set(SOURCES main.cpp)

add_executable(test_shmo ${SOURCES} ${HEADERS})
target_link_libraries(test_shmo shmocore gtest pthread)
target_include_directories(test_shmo PUBLIC ${PROJECT_ROOT_DIR}/src)
