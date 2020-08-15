cmake_minimum_required(VERSION 3.7)
project(AlgorithmTraining)

set(CMAKE_CXX_STANDARD_REQUIRED 11)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(PROJECT_ROOT_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJECT_OUTPUT_BIN_PATH "${CMAKE_BINARY_DIR}/bin")
set(PROJECT_OUTPUT_LIB_PATH "${CMAKE_BINARY_DIR}/lib")
set(PROJECT_OUTPUT_TEST_PATH "${CMAKE_BINARY_DIR}/test")

include_directories(Algorithm)
include_directories(src)

add_subdirectory(test)
add_subdirectory(src)
add_subdirectory(OpenSource/googletest)
