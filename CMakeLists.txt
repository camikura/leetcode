cmake_minimum_required(VERSION 3.30)

project(tests)

include_directories(/opt/homebrew/include)
link_directories(/opt/homebrew/lib)

set(CMAKE_CXX_STANDARD 17)

add_executable(run_tests
  src/001_two_sum.cpp
  src/009_palindrome_number.cpp
  src/013_roman_to_integer.cpp
  src/014_longest_common_prefix.cpp
  src/020_valid_parentheses.cpp
  src/021_merge_two_sorted_lists.cpp
  src/026_remove_duplicates_from_sorted_array.cpp
  src/027_remove_element.cpp
  src/067_add_binary.cpp
  src/069_sqrt_x.cpp
)

target_link_libraries(run_tests gtest gtest_main pthread)
