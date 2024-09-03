/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
 public:
  int mySqrt(int x) {
    long i = 1;
    while (i <= x) {
      if (i * i == (long)x) {
        return i;
      } else if (i * i > x) {
        return i - 1;
      }
      i++;
    }
    return 0;
  }
};
// @lc code=end
