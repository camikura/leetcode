/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

#include <vector>
#include <gtest/gtest.h>

using namespace std;

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

TEST(p066_plus_one, case1) {
  vector<int> nums{1, 2, 3};
  vector<int> result{1, 2, 4};
  EXPECT_EQ(result, Solution().plusOne(nums));
}

TEST(p066_plus_one, case2) {
  vector<int> nums{4, 3, 2, 1};
  vector<int> result{4, 3, 2, 2};
  EXPECT_EQ(result, Solution().plusOne(nums));
}

TEST(p066_plus_one, case3) {
  vector<int> nums{9};
  vector<int> result{1, 0};
  EXPECT_EQ(result, Solution().plusOne(nums));
}
