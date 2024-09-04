/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

#include <string>
#include <gtest/gtest.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int j = 0;
    int start = 0;
    for (auto i = s.length(); i > 0; i--) {
      if (!start && s[i - 1] != ' ') {
        start = 1;
      }
      if (start) {
        if (s[i - 1] == ' ') {
          return j;
        } else {
          j++;
        }
      }
    }
    return j;
  }
};
// @lc code=end

TEST(p058_length_of_last_word, case1) {
  EXPECT_EQ(5, Solution().lengthOfLastWord("Hello World"));
}

TEST(p058_length_of_last_word, case2) {
  EXPECT_EQ(4, Solution().lengthOfLastWord("   fly me   to   the moon  "));
}

TEST(p058_length_of_last_word, case3) {
  EXPECT_EQ(6, Solution().lengthOfLastWord("luffy is still joyboy"));
}
