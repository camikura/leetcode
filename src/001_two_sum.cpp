/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>
#include <map>
#include <gtest/gtest.h>

using namespace std;

// @lc code=start
class Solution {
 public:
  std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> m;

    for (auto i = 0; i < nums.size(); i++) {
      int num = nums[i];
      int diff = target - num;
      auto it = m.find(diff);
      if (it != m.end()) {
        return {it->second, i};
      }
      m[num] = i;
    }

    return {};
  }
};
// @lc code=end

TEST(p001_two_sum, case1) {
  vector<int> nums{2, 7, 11, 15};
  vector<int> result{0, 1};
  EXPECT_EQ(result, Solution().twoSum(nums, 9));
}

TEST(p001_two_sum, case2) {
  vector<int> nums{3, 2, 4};
  vector<int> result{1, 2};
  EXPECT_EQ(result, Solution().twoSum(nums, 6));
}

TEST(p001_two_sum, case3) {
  vector<int> nums{3, 3};
  vector<int> result{0, 1};
  EXPECT_EQ(result, Solution().twoSum(nums, 6));
}
