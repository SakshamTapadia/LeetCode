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

    // Sort the linked list using merge sort
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;

        // Step 1: Split the list into two halves
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Cut the list into two halves
        prev->next = nullptr;

        // Step 2: Sort each half
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        // Step 3: Merge sorted halves
        return mergeTwoLists(l1, l2);
    }
};
