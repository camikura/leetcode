/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start

#ifdef NOT_LEETCODE
#include <leetcode.h>
#endif

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (!list1) return list2;
    if (!list2) return list1;

    if (list1->val <= list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    }
  }

  ListNode* createList(std::initializer_list<int> vals) {
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
TEST(p021_merge_two_sorted_lists, case1) {
  ListNode* list1 = Solution().createList({1, 2, 4});
  ListNode* list2 = Solution().createList({1, 3, 4});
  ListNode* result = Solution().createList({1, 1, 2, 3, 4, 4});

  ListNode* mergedList = Solution().mergeTwoLists(list1, list2);

  EXPECT_TRUE(Solution().areListsEqual(result, mergedList));
}

TEST(p021_merge_two_sorted_lists, case2) {
  ListNode* list1 = Solution().createList({});
  ListNode* list2 = Solution().createList({});
  ListNode* result = Solution().createList({});

  ListNode* mergedList = Solution().mergeTwoLists(list1, list2);

  EXPECT_TRUE(Solution().areListsEqual(result, mergedList));
}

TEST(p021_merge_two_sorted_lists, case3) {
  ListNode* list1 = Solution().createList({});
  ListNode* list2 = Solution().createList({0});
  ListNode* result = Solution().createList({0});

  ListNode* mergedList = Solution().mergeTwoLists(list1, list2);

  EXPECT_TRUE(Solution().areListsEqual(result, mergedList));
}
#endif
