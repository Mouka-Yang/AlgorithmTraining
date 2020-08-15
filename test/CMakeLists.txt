set(TEST_BINARY ${CMAKE_PROJECT_NAME}_test)

file(
  GLOB_RECURSE TEST_SOURCES
  LIST_DIRECTORIES false
  *.h *.cpp)

set(SOURCES ${TEST_SOURCES})
add_executable(${TEST_BINARY} ${SOURCES})
add_test(NAME ${TEST_BINARY} COMMAND ${TEST_BINARY})

target_link_libraries(${TEST_BINARY} PUBLIC add gtest)
