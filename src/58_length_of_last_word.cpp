/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

#ifndef LEETCODE_H
#define LEETCODE_H

#include <string>
using namespace std;

#endif

// @lc code=start
class Solution {
 public:
  int lengthOfLastWord(string s) {
    int j = 0;
    int start = 0;
    for (auto i = s.length(); i > 0; i--) {
      if (!start && s[i - 1] != ' ') {
        start = 1;
      }
      if (start) {
        if (s[i - 1] == ' ') {
          return j;
        } else {
          j++;
        }
      }
    }
    return j;
  }
};
// @lc code=end
