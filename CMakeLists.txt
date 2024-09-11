cmake_minimum_required(VERSION 3.30)

project(leetcode)

include_directories(include /opt/homebrew/include)
link_directories(/opt/homebrew/lib)

set(CMAKE_CXX_STANDARD 20)

add_executable(run_tests
  # easy
  src/001_two_sum.cc
  src/009_palindrome_number.cc
  src/013_roman_to_integer.cc
  src/014_longest_common_prefix.cc
  src/020_valid_parentheses.cc
  src/021_merge_two_sorted_lists.cc
  src/026_remove_duplicates_from_sorted_array.cc
  src/027_remove_element.cc
  src/028_find_the_index_of_the_first_occurrence_in_a_string.cc
  src/035_search_insert_position.cc
  src/058_length_of_last_word.cc
  src/066_plus_one.cc
  src/067_add_binary.cc
  src/069_sqrt_x.cc
  src/070_climbing_stairs.cc
  src/083_remove_duplicates_from_sorted_list.cc
  src/088_merge_sorted_array.cc
  src/094_binary_tree_inorder_traversal.cc

  # midium
  src/002_add_two_numbers.cc
  src/003_longest_substring_without_repeating_characters.cc
  src/005_longest_palindromic_substring.cc
  src/006_zigzag_conversion.cc
  src/007_reverse_integer.cc
  src/008_string_to_integer_atoi.cc
)

add_definitions(-DNOT_LEETCODE)

target_link_libraries(run_tests gtest gtest_main pthread)

# tests
add_test(NAME run_tests COMMAND run_tests)
enable_testing()
