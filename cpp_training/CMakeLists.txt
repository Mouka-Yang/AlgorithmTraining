add_executable(unittest_cpp_training
    regex_test.cpp
)
target_link_libraries(unittest_cpp_training PUBLIC gmock_main)
