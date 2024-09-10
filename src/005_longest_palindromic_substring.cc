/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <leetcode.h>

// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.length() == 1)
      return s;

    int index = 0;
    string result = "";

    while (index < s.length()) {
      int len1 = findPalindrome(s, index, index);
      int len2 = findPalindrome(s, index, index + 1);
      int len = max(len1, len2);

      if (len > (int)result.length()) {
        result = s.substr(index - (len - 1) / 2, len);
      }
      index++;
    }

    return result;
  }

  int findPalindrome(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      left--;
      right++;
    }

    return right - left - 1;
  }
};
// @lc code=end

TEST(p005_longest_palindromic_substring, case1) {
  auto result = Solution().longestPalindrome("babad");
  EXPECT_EQ(result, "bab");
}

TEST(p005_longest_palindromic_substring, case2) {
  auto result = Solution().longestPalindrome("cbbd");
  EXPECT_EQ(result, "bb");
}

TEST(p005_longest_palindromic_substring, case3) {
  auto result = Solution().longestPalindrome(
      "pihoigwlvzvtrugdolvtzrkyelaqdvbijzmkhebzawboaxkdjyfocpewwztffuaibcqurwwm"
      "ijmvrnpfcoglyxpxkrbhupoxcafabxtoecodsjgngrionuvzaiigevuvruxxiwpjzjlqgeng"
      "lhprcgzgpdzabrjhkbtfrbmwpcszepxhwiwdhvnpsmhhaiqsbeiwsaeomqtzcpjzfknejxlx"
      "wtpkufanhuoyjgihdzhtxnyctazzvnttjspfztjurdwmmzrvobcatkorfhpieoqfetcglemb"
      "kgbexsznuduhrfoxkbswkanqwfkoktnnujqetijaqhrxuhkgsezfdrncbaltctwcourdbpdw"
      "hqlsxfwsoaduaqkbjeekwwykptjthhtokrvzsuelsywyznqscnwiszogzqvfsgggzltlvzkl"
      "linpfaigswquqfvabbzvestwxhbnfjhnvfhyxalchmtkcwnyyrbwjsoqooypwteozbivqiyl"
      "dpqlykxinmzkgnmfbobgjivlzubfen");
  EXPECT_EQ(result, "thht");
}

TEST(p005_longest_palindromic_substring, case4) {
  auto result = Solution().longestPalindrome("bb");
  EXPECT_EQ(result, "bb");
}
