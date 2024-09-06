/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

// @lc code=start
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      while (strs[i].find(prefix) != 0) {
        prefix = prefix.substr(0, prefix.length() - 1);
        if (prefix.empty())
          return "";
      }
    }
    return prefix;
  }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p014_longest_common_prefix, case1) {
  vector<string> strs{"flower", "flow", "flight"};
  EXPECT_EQ("fl", Solution().longestCommonPrefix(strs));
}

TEST(p014_longest_common_prefix, case2) {
  vector<string> strs{"dog", "racecar", "car"};
  EXPECT_EQ("", Solution().longestCommonPrefix(strs));
}
#endif
