
set(TEST_BINARY ${CMAKE_PROJECT_NAME}_test)

# file(
#   GLOB_RECURSE TEST_SOURCES
#   LIST_DIRECTORIES false
#   *.h *.cpp)

# set(SOURCES ${TEST_SOURCES})
# add_executable(${TEST_BINARY} ${SOURCES})
# target_link_libraries(${TEST_BINARY} PUBLIC add gtest)

add_test(NAME ${TEST_BINARY} COMMAND ${TEST_BINARY})

add_executable(unittest_96 ${LEETCODE_PATH}/96.cpp)
target_link_libraries(unittest_96 PUBLIC gtest_main)

add_executable(unittest_503 ${LEETCODE_PATH}/503.cpp)
target_link_libraries(unittest_503 PUBLIC gtest_main)

add_executable(unittest_739 ${LEETCODE_PATH}/739.cpp)
target_link_libraries(unittest_739 PUBLIC gtest_main)


