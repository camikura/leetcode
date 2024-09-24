/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <leetcode.h>

// @lc code=start
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {
      // remove duplicated values
      if (i > 0 && nums[i] == nums[i - 1]) {
        continue;
      }

      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        int total = nums[i] + nums[j] + nums[k];

        if (total > 0) {
          k--;
        } else if (total < 0) {
          j++;
        } else {
          res.push_back({nums[i], nums[j], nums[k]});
          j++;

          // skip duplicated values
          while (nums[j] == nums[j - 1] && j < k)
            j++;
        }
      }
    }

    return res;
  }
};
// @lc code=end

TEST(p015_3_sum, case1) {
  vector<int> nums{-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result{{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(result, Solution().threeSum(nums));
}

TEST(p015_3_sum, case2) {
  vector<int> nums{0, 1, 1};
  vector<vector<int>> result{};
  EXPECT_EQ(result, Solution().threeSum(nums));
}

TEST(p015_3_sum, case3) {
  vector<int> nums{0, 0, 0};
  vector<vector<int>> result{{0, 0, 0}};
  EXPECT_EQ(result, Solution().threeSum(nums));
}
