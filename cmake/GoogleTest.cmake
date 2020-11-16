set(GOOGLETEST_PREFIX "${CMAKE_BINARY_DIR}/open_source/googletest-download/")
configure_file(${CMAKE_CURRENT_LIST_DIR}/GoogleTest.cmake.in ${GOOGLETEST_PREFIX}/CMakeLists.txt)

execute_process(
    COMMAND ${CMAKE_COMMAND} -G ${CMAKE_GENERATOR} .
    WORKING_DIRECTORY ${GOOGLETEST_PREFIX}
)

execute_process(
    COMMAND ${CMAKE_COMMAND} --build .
    WORKING_DIRECTORY ${GOOGLETEST_PREFIX}
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(
    ${CMAKE_BINARY_DIR}/googletest-src
    ${CMAKE_BINARY_DIR}/googletest-build
    EXCLUDE_FROM_ALL
)
