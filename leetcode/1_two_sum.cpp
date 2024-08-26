/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <vector>
#include <map>

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
