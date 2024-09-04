/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int j = 0;
    for (auto i = 0; i < nums.size(); i++) {
      if (nums[i] == target) {
        return i;
      } else if (nums[i] < target) {
        j = i + 1;
      }
    }
    return j;
  }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p035_search_insert_position, case1) {
  vector<int> nums{1, 3, 5, 6};
  EXPECT_EQ(2, Solution().searchInsert(nums, 5));
}

TEST(p035_search_insert_position, case2) {
  vector<int> nums{1, 3, 5, 6};
  EXPECT_EQ(1, Solution().searchInsert(nums, 2));
}

TEST(p035_search_insert_position, case3) {
  vector<int> nums{1, 3, 5, 6};
  EXPECT_EQ(4, Solution().searchInsert(nums, 7));
}
#endif
