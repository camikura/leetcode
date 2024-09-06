/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

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

#ifdef NOT_LEETCODE
TEST(p069_sqrt_x, case1) {
  EXPECT_EQ(2, Solution().mySqrt(4));
}

TEST(p069_sqrt_x, case2) {
  EXPECT_EQ(2, Solution().mySqrt(8));
}

TEST(p069_sqrt_x, case3) {
  EXPECT_EQ(3, Solution().mySqrt(9));
}
#endif
