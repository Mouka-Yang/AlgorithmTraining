add_executable(unittest_96 ${LEETCODE_PATH}/96.cpp)
target_link_libraries(unittest_96 PUBLIC gtest_main)

add_executable(unittest_503 ${LEETCODE_PATH}/503.cpp)
target_link_libraries(unittest_503 PUBLIC gtest_main)

add_executable(unittest_739 ${LEETCODE_PATH}/739.cpp)
target_link_libraries(unittest_739 PUBLIC gtest_main)

add_executable(unittest_547 ${LEETCODE_PATH}/547.cpp)
target_link_libraries(unittest_547 PUBLIC gtest_main)

add_executable(data_struct_test 
    ${DATA_STRUCT_PATH}/disjoint_set.cpp
)
target_link_libraries(data_struct_test PUBLIC gtest_main)

add_test(NAME data_struct_test COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data_struct_test)
