/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

#include <leetcode.h>

// @lc code=start
class Solution {
 public:
  int reverse(int x) {
    long long res = 0;
    while (x < 0 || x > 0) {
      res *= 10;
      res += x % 10;
      x /= 10;
    }

    if (res < INT_MIN || res > INT_MAX - 1)
      return 0;

    return res;
  }
};
// @lc code=end

TEST(p007_reverse_integer, case1) {
  EXPECT_EQ(321, Solution().reverse(123));
}

TEST(p007_reverse_integer, case2) {
  EXPECT_EQ(-321, Solution().reverse(-123));
}

TEST(p007_reverse_integer, case3) {
  EXPECT_EQ(21, Solution().reverse(120));
}

TEST(p007_reverse_integer, case4) {
  EXPECT_EQ(0, Solution().reverse(1534236469));
}

TEST(p007_reverse_integer, case5) {
  EXPECT_EQ(0, Solution().reverse(-2147483648));
}
