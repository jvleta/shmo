set(SOURCES
    ${PROJECT_ROOT_DIR}/src/shmodata.cpp
    ${PROJECT_ROOT_DIR}/src/shmosolver.cpp
)

set(HEADERS
    ${PROJECT_ROOT_DIR}/src/shmodata.h
    ${PROJECT_ROOT_DIR}/src/shmosolver.h
)

add_definitions("-s DEMANGLE_SUPPORT=1 --preload-file ${CMAKE_SOURCE_DIR}/assets --bind")
add_executable(shmo ${SOURCES} ${HEADERS})