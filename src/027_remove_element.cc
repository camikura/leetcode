/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

// @lc code=start
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int j = 0;
    for (auto i = 0; i < nums.size(); i++) {
      if (nums[i] != val) {
        nums[j++] = nums[i];
      }
    }
    return j;
  }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p027_remove_element, case1) {
  vector<int> nums{3, 2, 2, 3};
  EXPECT_EQ(2, Solution().removeElement(nums, 3));

  EXPECT_EQ(2, nums[0]);
  EXPECT_EQ(2, nums[1]);
}

TEST(p027_remove_element, case2) {
  vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
  EXPECT_EQ(5, Solution().removeElement(nums, 2));

  EXPECT_EQ(0, nums[0]);
  EXPECT_EQ(1, nums[1]);
  EXPECT_EQ(3, nums[2]);
  EXPECT_EQ(0, nums[3]);
  EXPECT_EQ(4, nums[4]);
}
#endif
