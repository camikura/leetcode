/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include <leetcode.h>

// @lc code=start
class Solution {

 public:
  int nums[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  string words[13] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                      "XL", "X",  "IX", "V",  "IV", "I"};

  string intToRoman(int num) {
    string res = "";
    int i = 0;
    while (num > 0) {
      if (num >= nums[i]) {
        res += words[i];
        num -= nums[i];
      } else {
        i++;
      }
    }

    return res;
  }
};
// @lc code=end

TEST(p012_integer_to_roman2, case1) {
  EXPECT_EQ("MMMDCCXLIX", Solution().intToRoman(3749));
}

TEST(p012_integer_to_roman2, case2) {
  EXPECT_EQ("LVIII", Solution().intToRoman(58));
}

TEST(p012_integer_to_roman2, case3) {
  EXPECT_EQ("MCMXCIV", Solution().intToRoman(1994));
}
