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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head || !head->next) return head;

        ListNode* temp = head;
        ListNode* firstPrev = nullptr;

        // Find k-th node from beginning
        int n = 1;
        while (n < k) {
            firstPrev = temp;
            temp = temp->next;
            n++;
        }
        ListNode* first = temp;

        // Find k-th node from end
        ListNode* second = head;
        ListNode* secondPrev = nullptr;
        temp = first;
        while (temp->next) {
            secondPrev = second;
            temp = temp->next;
            second = second->next;
        }

        // Change previous pointers
        if (firstPrev) firstPrev->next = second;
        if (secondPrev) secondPrev->next = first;

        // Swap next pointers
        temp = first->next;
        first->next = second->next;
        second->next = temp;

        // Handle head cases
        if (k == 1) return second;
        if (second == head) return first;

        return head;
    }
};