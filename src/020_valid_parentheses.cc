/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <map>
#include <string>
#include <stack>
#include <gtest/gtest.h>

// @lc code=start
class Solution {
 public:
  bool isValid(std::string s) {
    std::stack<char> st;
    std::map<char, char> b = {
        {')', '('},
        {'}', '{'},
        {']', '['},
    };

    for (auto i = 0; i < s.length(); i++) {
      auto it = b.find(s[i]);
      if (it == b.end()) {
        st.push(s[i]);
      } else {
        if (st.empty()) return false;
        if (b[s[i]] != st.top()) return false;

        st.pop();
      }
    }

    return st.empty();
  }
};
// @lc code=end

TEST(p020_valid_parentheses, case1) {
  EXPECT_EQ(true, Solution().isValid("()"));
}

TEST(p020_valid_parentheses, case2) {
  EXPECT_EQ(true, Solution().isValid("()[]{}"));
}

TEST(p020_valid_parentheses, case3) {
  EXPECT_EQ(false, Solution().isValid("(]"));
}

TEST(p020_valid_parentheses, case4) {
  EXPECT_EQ(true, Solution().isValid("([])"));
}
