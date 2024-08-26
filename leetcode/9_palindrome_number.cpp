/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

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
