set(SOURCES
    ${PROJECT_ROOT_DIR}/src/shmodata.cpp
    ${PROJECT_ROOT_DIR}/src/shmosolver.cpp
)

set(HEADERS
    ${PROJECT_ROOT_DIR}/src/shmodata.h
    ${PROJECT_ROOT_DIR}/src/shmosolver.h
    ${PROJECT_ROOT_DIR}/src/matplotlibcpp.h
)

add_library(shmocore ${SOURCES} ${HEADERS})
target_link_libraries(shmocore ${PYTHON_LIBRARY})
target_include_directories(shmocore PUBLIC ${PYTHON_INCLUDE_DIRS})

add_executable(shmo main.cpp)
target_link_libraries(shmo shmocore)
