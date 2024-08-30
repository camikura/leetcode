/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include <string>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::string longestCommonPrefix(std::vector<std::string>& strs) {
    std::string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      while (strs[i].find(prefix) != 0) {
        prefix = prefix.substr(0, prefix.length() - 1);
        if (prefix.empty()) return "";
      }
    }
    return prefix;
  }
};
// @lc code=end
