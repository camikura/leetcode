/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

// @lc code=start
class Solution {
 public:
  int romanToInt(std::string s) {
    std::map<char, int> m{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                          {'C', 100}, {'D', 500}, {'M', 1000}};

    int ans = 0;
    int len = s.length();
    for (auto i = 0; i < len; i++) {
      if (i < len - 1 && m[s[i]] < m[s[i + 1]]) {
        ans -= m[s[i]];
      } else {
        ans += m[s[i]];
      }
    }

    return ans;
  }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p013_roman_to_integer, case1) {
  EXPECT_EQ(3, Solution().romanToInt("III"));
}

TEST(p013_roman_to_integer, case2) {
  EXPECT_EQ(58, Solution().romanToInt("LVIII"));
}

TEST(p013_roman_to_integer, case3) {
  EXPECT_EQ(1994, Solution().romanToInt("MCMXCIV"));
}
#endif
