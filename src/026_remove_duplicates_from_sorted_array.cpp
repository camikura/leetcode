/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#ifndef LEETCODE_H
#define LEETCODE_H

#include <vector>
using namespace std;

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
