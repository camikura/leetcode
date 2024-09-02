/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#ifndef LEETCODE_H
#define LEETCODE_H

#include <vector>
using namespace std;

#endif

// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int o = 1;
    auto i = digits.size();

    while (o && i > 0) {
      if (digits[i - 1] == 9) {
        digits[i - 1] = 0;
      } else {
        digits[i - 1] += 1;
        o = 0;
      }
      i--;
    }

    if (o) {
      digits.insert(digits.begin(), 1);
    }

    return digits;
  }
};
// @lc code=end
