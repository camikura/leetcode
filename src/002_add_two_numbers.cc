/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

#include <leetcode.h>

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    int carry = 0;

    while (l1 != nullptr || l2 != nullptr || carry > 0) {
      int num1 = l1 ? l1->val : 0;
      int num2 = l2 ? l2->val : 0;
      int num = num1 + num2 + carry;
      carry = num / 10;

      int val = num % 10;
      if (!head) {
        tail = head = new ListNode(val);
      } else {
        tail = tail->next = new ListNode(val);
      }

      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }

    return head;
  }

  ListNode* createList(initializer_list<int> vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : vals) {
      if (!head) {
        tail = head = new ListNode(val);
      } else {
        tail = tail->next = new ListNode(val);
      }
    }

    return head;
  }

  bool areListsEqual(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val != l2->val) {
        return false;
      }
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }

    return l1 == nullptr && l2 == nullptr;
  }
};
// @lc code=end

TEST(p002_add_two_numbers, case1) {
  ListNode* l1 = Solution().createList({2, 4, 3});
  ListNode* l2 = Solution().createList({5, 6, 4});
  ListNode* output = Solution().createList({7, 0, 8});
  ListNode* result = Solution().addTwoNumbers(l1, l2);

  EXPECT_TRUE(Solution().areListsEqual(result, output));
}

TEST(p002_add_two_numbers, case2) {
  ListNode* l1 = Solution().createList({0});
  ListNode* l2 = Solution().createList({0});
  ListNode* output = Solution().createList({0});
  ListNode* result = Solution().addTwoNumbers(l1, l2);

  EXPECT_TRUE(Solution().areListsEqual(result, output));
}

TEST(p002_add_two_numbers, case3) {
  ListNode* l1 = Solution().createList({9, 9, 9, 9, 9, 9, 9});
  ListNode* l2 = Solution().createList({9, 9, 9, 9});
  ListNode* output = Solution().createList({8, 9, 9, 9, 0, 0, 0, 1});
  ListNode* result = Solution().addTwoNumbers(l1, l2);

  EXPECT_TRUE(Solution().areListsEqual(result, output));
}
