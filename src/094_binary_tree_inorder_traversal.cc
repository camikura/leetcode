/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
  }

  TreeNode* createTree(const vector<int>& values) {
    if (values.empty() || values[0] == -1)
      return nullptr;

    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < values.size()) {
      TreeNode* current = q.front();
      q.pop();

      if (i < values.size() && values[i] != -1) {
        current->left = new TreeNode(values[i]);
        q.push(current->left);
      }
      i++;

      if (i < values.size() && values[i] != -1) {
        current->right = new TreeNode(values[i]);
        q.push(current->right);
      }
      i++;
    }

    return root;
  }

 private:
  void inorderHelper(TreeNode* node, vector<int>& result) {
    if (node != nullptr) {
      inorderHelper(node->left, result);
      result.push_back(node->val);
      inorderHelper(node->right, result);
    }
  }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p094_merge_sorted_array, case1) {
  vector<int> rootValues{1, -1, 2, 3};
  vector<int> result{1, 3, 2};
  auto root = Solution().createTree(rootValues);
  EXPECT_EQ(result, Solution().inorderTraversal(root));
}

TEST(p094_merge_sorted_array, case2) {
  vector<int> rootValues{1, 2, 3, 4, 5, -1, 8, -1, -1, 6, 7, 9};
  vector<int> result{4, 2, 6, 5, 7, 1, 3, 9, 8};
  auto root = Solution().createTree(rootValues);
  EXPECT_EQ(result, Solution().inorderTraversal(root));
}

TEST(p094_merge_sorted_array, case3) {
  vector<int> rootValues{};
  vector<int> result{};
  auto root = Solution().createTree(rootValues);
  EXPECT_EQ(result, Solution().inorderTraversal(root));
}

TEST(p094_merge_sorted_array, case4) {
  vector<int> rootValues{1};
  vector<int> result{1};
  auto root = Solution().createTree(rootValues);
  EXPECT_EQ(result, Solution().inorderTraversal(root));
}
#endif
