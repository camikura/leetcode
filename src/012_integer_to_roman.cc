/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include <leetcode.h>

// @lc code=start
class Solution {
 public:
  string intToRoman(int num) {
    string res = "";
    while (num > 0) {

      // X000
      while (num >= 1000) {
        res += "M";
        num -= 1000;
      }

      // X00
      if (num >= 900) {
        res += "CM";
        num -= 900;
      } else if (num >= 500) {
        res += "D";
        num -= 500;
      } else if (num >= 400) {
        res += "CD";
        num -= 400;
      }
      while (num >= 100) {
        res += "C";
        num -= 100;
      }

      // X0
      if (num >= 90) {
        res += "XC";
        num -= 90;
      } else if (num >= 50) {
        res += "L";
        num -= 50;
      } else if (num >= 40) {
        res += "XL";
        num -= 40;
      }
      while (num >= 10) {
        res += "X";
        num -= 10;
      }

      // X
      if (num >= 9) {
        res += "IX";
        num -= 9;
      } else if (num >= 5) {
        res += "V";
        num -= 5;
      } else if (num >= 4) {
        res += "IV";
        num -= 4;
      }
      while (num >= 1) {
        res += "I";
        num -= 1;
      }
    }

    return res;
  }
};
// @lc code=end

TEST(p012_integer_to_roman, case1) {
  EXPECT_EQ("MMMDCCXLIX", Solution().intToRoman(3749));
}

TEST(p012_integer_to_roman, case2) {
  EXPECT_EQ("LVIII", Solution().intToRoman(58));
}

TEST(p012_integer_to_roman, case3) {
  EXPECT_EQ("MCMXCIV", Solution().intToRoman(1994));
}
