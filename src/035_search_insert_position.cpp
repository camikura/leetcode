/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#ifndef LEETCODE_H
#define LEETCODE_H

#include <vector>
using namespace std;

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
