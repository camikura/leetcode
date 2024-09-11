/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

#include <leetcode.h>

// @lc code=start
class Solution {
 public:
  int myAtoi(string s) {

    long long res = 0;
    int started = 0;
    int minus = 0;

    for (auto i = 0; i < s.length(); i++) {
      int c = s[i];

      if (c == '0') {
        started++;
        if (res != 0)
          res *= 10;
      }

      else if (c >= '1' && c <= '9') {
        started++;
        res *= 10;
        if (minus)
          res -= c - '0';
        else
          res += c - '0';

      }

      else if (c == '-') {
        if (started)
          return res;

        minus = 1;
        started++;
      }

      else if (c == '+') {
        if (started)
          return res;

        started++;
      }

      else if (c == ' ') {
        if (started)
          return res;
      }

      else {
        return res;
      }

      if (res > INT_MAX)
        return INT_MAX;
      if (res < INT_MIN)
        return INT_MIN;
    }

    return res;
  }
};
// @lc code=end

TEST(p008_string_to_integer_atoi, case1) {
  EXPECT_EQ(42, Solution().myAtoi("42"));
}

TEST(p008_string_to_integer_atoi, case2) {
  EXPECT_EQ(-42, Solution().myAtoi(" -042"));
}

TEST(p008_string_to_integer_atoi, case3) {
  EXPECT_EQ(1337, Solution().myAtoi("1337c0d3"));
}

TEST(p008_string_to_integer_atoi, case4) {
  EXPECT_EQ(0, Solution().myAtoi("0-1"));
}

TEST(p008_string_to_integer_atoi, case5) {
  EXPECT_EQ(0, Solution().myAtoi("words and 987"));
}

TEST(p008_string_to_integer_atoi, case6) {
  EXPECT_EQ(-2147483648, Solution().myAtoi("-91283472332"));
}

TEST(p008_string_to_integer_atoi, case7) {
  EXPECT_EQ(1, Solution().myAtoi("+1"));
}

TEST(p008_string_to_integer_atoi, case8) {
  EXPECT_EQ(0, Solution().myAtoi("+-12"));
}

TEST(p008_string_to_integer_atoi, case9) {
  EXPECT_EQ(0, Solution().myAtoi("   +0 123"));
}

TEST(p008_string_to_integer_atoi, case10) {
  EXPECT_EQ(2147483647, Solution().myAtoi("20000000000000000000"));
}
