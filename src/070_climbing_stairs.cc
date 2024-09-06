/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

// @lc code=start
class Solution {
 public:
  int climbStairs(int n) {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;

    int prev1 = 2, prev2 = 1;

    for (auto i = 3; i < n + 1; i++) {
      auto current = prev1 + prev2;
      prev2 = prev1;
      prev1 = current;
    }

    return prev1;
  }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p070_climbing_stairs, case1) {
  EXPECT_EQ(2, Solution().climbStairs(2));
}

TEST(p070_climbing_stairs, case2) {
  EXPECT_EQ(3, Solution().climbStairs(3));
}

TEST(p070_climbing_stairs, case3) {
  EXPECT_EQ(5, Solution().climbStairs(4));
}

TEST(p070_climbing_stairs, case4) {
  EXPECT_EQ(8, Solution().climbStairs(5));
}
#endif
