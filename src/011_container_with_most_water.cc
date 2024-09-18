/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <leetcode.h>

// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int lp = 0, rp = height.size() - 1;
    int max_area = -1;

    while (lp < rp) {
      int lheight = height[lp];
      int rheight = height[rp];

      if (lheight <= rheight) {
        int current_area = lheight * (rp - lp);
        if (current_area > max_area) {
          max_area = current_area;
        }
        lp++;
      } else {
        int current_area = rheight * (rp - lp);
        if (current_area > max_area) {
          max_area = current_area;
        }
        rp--;
      }
    }

    return max_area;
  }
};
// @lc code=end

TEST(p011_container_with_most_water, case1) {
  vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
  EXPECT_EQ(49, Solution().maxArea(height));
}

TEST(p011_container_with_most_water, case2) {
  vector<int> height{1, 1};
  EXPECT_EQ(1, Solution().maxArea(height));
}
