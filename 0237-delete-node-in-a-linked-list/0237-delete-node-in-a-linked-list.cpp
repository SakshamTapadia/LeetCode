/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* n1 = node;
        ListNode* n2 = node->next;
        while (true) {
            n1->val = n2->val;
            if (n2->next == NULL)
                break;
            n1 = n2;
            n2 = n2->next;
        }
        n1->next = NULL;
    }
};