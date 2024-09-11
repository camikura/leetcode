/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

#include <leetcode.h>

// @lc code=start
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;

    string res = "";
    int inc = 2 * (numRows - 1);
    for (auto r = 0; r < numRows; r++) {
      for (auto i = r; i < s.length(); i += inc) {
        res += s[i];

        // これがないと折り返し時の文字を拾えない
        if (r > 0 && r < numRows - 1 && i + inc - 2 * r < s.length()) {
          res += s[i + inc - 2 * r];
        }
      }
    }

    return res;
  }
};
// @lc code=end

TEST(p006_zigzag_conversion, case1) {
  EXPECT_EQ("PAHNAPLSIIGYIR", Solution().convert("PAYPALISHIRING", 3));
}

TEST(p006_zigzag_conversion, case2) {
  EXPECT_EQ("PINALSIGYAHRPI", Solution().convert("PAYPALISHIRING", 4));
}

TEST(p006_zigzag_conversion, case3) {
  EXPECT_EQ("A", Solution().convert("A", 1));
}
