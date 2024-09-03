/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

#ifndef LEETCODE_H
#define LEETCODE_H

#include <vector>
using namespace std;

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
