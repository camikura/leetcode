/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include <map>
#include <string>

// @lc code=start
class Solution {
 public:
  int romanToInt(std::string s) {
    std::map<char, int> m{{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                          {'C', 100}, {'D', 500}, {'M', 1000}};

    int ans = 0;
    int len = s.length();
    for (auto i = 0; i < len; i++) {
      if (i < len - 1 && m[s[i]] < m[s[i + 1]]) {
        ans -= m[s[i]];
      } else {
        ans += m[s[i]];
      }
    }

    return ans;
  }
};
// @lc code=end
