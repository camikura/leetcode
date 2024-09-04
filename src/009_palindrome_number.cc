/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    int t = x;
    long long b = 0;

    while (x > 0) {
      b = b * 10 + x % 10;
      x /= 10;
    }

    return t == b;
  }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p009_palindrome_number, case1) {
  EXPECT_EQ(true, Solution().isPalindrome(121));
}

TEST(p009_palindrome_number, case2) {
  EXPECT_EQ(false, Solution().isPalindrome(-121));
}

TEST(p009_palindrome_number, case3) {
  EXPECT_EQ(false, Solution().isPalindrome(10));
}
#endif