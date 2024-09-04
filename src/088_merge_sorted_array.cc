/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

// @lc code=start
class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for (auto i = m; i < m + n; i++) {
      nums1[i] = nums2[i - m];
    }

    sort(nums1.begin(), nums1.end());
  }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p088_merge_sorted_array, case1) {
  vector<int> nums1{1, 2, 3, 0, 0, 0};
  vector<int> nums2{2, 5, 6};
  vector<int> result{1, 2, 2, 3, 5, 6};
  Solution().merge(nums1, 3, nums2, 3);
  EXPECT_EQ(result, nums1);
}

TEST(p088_merge_sorted_array, case2) {
  vector<int> nums1{1};
  vector<int> nums2{};
  vector<int> result{1};
  Solution().merge(nums1, 1, nums2, 0);
  EXPECT_EQ(result, nums1);
}

TEST(p088_merge_sorted_array, case3) {
  vector<int> nums1{0};
  vector<int> nums2{1};
  vector<int> result{1};
  Solution().merge(nums1, 0, nums2, 1);
  EXPECT_EQ(result, nums1);
}
#endif
