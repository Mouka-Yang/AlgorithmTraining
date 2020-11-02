MACRO(add_leetcode_test problem_num)
    set(leetcode_target "unittest_${problem_num}")
    add_executable(${leetcode_target} ${LEETCODE_PATH}/${problem_num}.cpp)
    target_link_libraries(${leetcode_target} PUBLIC gtest_main)
    add_test(NAME ${leetcode_target} COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${leetcode_target})
ENDMACRO()

add_leetcode_test(96)
add_leetcode_test(547)
add_leetcode_test(503)
add_leetcode_test(739)
add_leetcode_test(684)
add_leetcode_test(200)
add_leetcode_test(200v2)

add_executable(data_struct_test 
    ${DATA_STRUCT_PATH}/disjoint_set.cpp
)
target_link_libraries(data_struct_test PUBLIC gtest_main)

add_test(NAME data_struct_test COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/data_struct_test)
