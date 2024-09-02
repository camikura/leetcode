/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#ifndef LEETCODE_H
#define LEETCODE_H

#include <string>
using namespace std;

#endif

// @lc code=start
class Solution {
 public:
  string addBinary(string a, string b) {
    string res;

    int carry = 0;
    int ai = a.length() - 1;
    int bi = b.length() - 1;

    while (ai >= 0 || bi >= 0 || carry) {
      if (ai >= 0) carry += a[ai--] - '0';
      if (bi >= 0) carry += b[bi--] - '0';

      res.insert(res.begin(), carry % 2 + '0');
      carry /= 2;
    }

    return res;
  }
};
// @lc code=end
