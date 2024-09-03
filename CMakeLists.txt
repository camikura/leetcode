cmake_minimum_required(VERSION 3.30)

project(tests)

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

set(CMAKE_CXX_STANDARD 17)

add_executable(run_tests
  src/001_two_sum.cpp
)

target_link_libraries(run_tests gtest gtest_main pthread)
