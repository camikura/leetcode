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
    int index = 0, len = 0;
    string word = "", res = "";

    while (index <= s.length()) {
      len = res.length() + 1;
      while (index + len <= s.length()) {
        word = s.substr(index, len);
        if (isPalindrome(word) && len > res.length()) {
          res = word;
        }
        len++;
      }
      index++;
    }

    return res;
  }

  bool isPalindrome(const string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
      if (s[left] != s[right])
        return false;
      left++;
      right--;
    }
    return true;
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
