/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

// @lc code=start
class Solution {
 public:
  int strStr(string haystack, string needle) { return haystack.find(needle); }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p028_find_the_index_of_the_first_occurrence_in_a_string, case1) {
  EXPECT_EQ(0, Solution().strStr("sadbutsad", "sad"));
}

TEST(p028_find_the_index_of_the_first_occurrence_in_a_string, case2) {
  EXPECT_EQ(-1, Solution().strStr("leetcode", "leeto"));
}
#endif
