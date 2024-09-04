/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

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
  ListNode* deleteDuplicates(ListNode* head) {
    if (head == NULL) {
      return head;
    }

    ListNode* curr = head;
    while (curr != NULL && curr->next != NULL) {
      if (curr->val == curr->next->val) {
        ListNode* next = curr->next->next;
        delete (curr->next);
        curr->next = next;
      } else {
        curr = curr->next;
      }
    }
    return head;
  }

  ListNode* createList(initializer_list<int> vals) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int val : vals) {
      if (!head) {
        head = new ListNode(val);
        tail = head;
      } else {
        tail->next = new ListNode(val);
        tail = tail->next;
      }
    }

    return head;
  }

  bool areListsEqual(ListNode* l1, ListNode* l2) {
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val != l2->val) {
        return false;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    return l1 == nullptr && l2 == nullptr;
  }
};
// @lc code=end

#ifdef NOT_LEETCODE
TEST(p083_remove_duplicates_from_sorted_list, case1) {
  ListNode* head = Solution().createList({1, 1, 2});
  ListNode* result = Solution().createList({1, 2});

  ListNode* uniqueSortedList = Solution().deleteDuplicates(head);

  EXPECT_TRUE(Solution().areListsEqual(result, uniqueSortedList));
}

TEST(p083_remove_duplicates_from_sorted_list, case2) {
  ListNode* head = Solution().createList({1, 1, 2, 2, 3});
  ListNode* result = Solution().createList({1, 2, 3});

  ListNode* uniqueSortedList = Solution().deleteDuplicates(head);

  EXPECT_TRUE(Solution().areListsEqual(result, uniqueSortedList));
}
#endif
