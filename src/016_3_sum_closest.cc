/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include <leetcode.h>

// @lc code=start
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) { return 0; }
};
// @lc code=end

TEST(p016_3_sum_closest, case1) {
  vector<int> nums{-1, 2, 1, -4};
  EXPECT_EQ(2, Solution().threeSumClosest(nums, 1));
}

TEST(p016_3_sum_closest, case2) {
  vector<int> nums{0, 0, 0};
  EXPECT_EQ(0, Solution().threeSumClosest(nums, 1));
}
