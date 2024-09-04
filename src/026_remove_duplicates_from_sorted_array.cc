/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int res = 1;
    for (auto i = 1; i < nums.size(); i++) {
      if (nums[i] != nums[i - 1]) {
        nums[res] = nums[i];
        res++;
      }
    }

    return res;
  }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p026_remove_duplicates_from_sorted_array, case1) {
  vector<int> nums{1, 1, 2};
  EXPECT_EQ(2, Solution().removeDuplicates(nums));

  EXPECT_EQ(1, nums[0]);
  EXPECT_EQ(2, nums[1]);
}

TEST(p026_remove_duplicates_from_sorted_array, case2) {
  vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  EXPECT_EQ(5, Solution().removeDuplicates(nums));

  EXPECT_EQ(0, nums[0]);
  EXPECT_EQ(1, nums[1]);
  EXPECT_EQ(2, nums[2]);
  EXPECT_EQ(3, nums[3]);
  EXPECT_EQ(4, nums[4]);
}
#endif
