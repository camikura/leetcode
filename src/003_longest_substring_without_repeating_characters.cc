/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <leetcode.h>

// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> seen;
    int start = 0, maxLength = 0;

    for (int end = 0; end < s.size(); end++) {
      while (seen.find(s[end]) != seen.end()) {
        seen.erase(s[start]);
        start++;
      }
      seen.insert(s[end]);
      maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
  }
};
// @lc code=end

TEST(p003_longest_substring_without_repeating_characters, case1) {
  EXPECT_EQ(3, Solution().lengthOfLongestSubstring("abcabcbb"));
}

TEST(p003_longest_substring_without_repeating_characters, case2) {
  EXPECT_EQ(1, Solution().lengthOfLongestSubstring("bbbbb"));
}

TEST(p003_longest_substring_without_repeating_characters, case3) {
  EXPECT_EQ(3, Solution().lengthOfLongestSubstring("pwwkew"));
}
