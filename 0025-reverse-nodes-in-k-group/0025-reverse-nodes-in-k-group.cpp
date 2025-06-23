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

ListNode* reverse(ListNode* head, ListNode* tail) {
    ListNode* prev = tail; //the prev is the node which is not included in the reversal
    while (head != tail) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}    

    ListNode* reverseKGroup(ListNode* head, int k) {
        if( head == NULL || k == 1) return head;

        ListNode* ptr = head ;
        for(int i=0;i<k;i++){
            if(!ptr) return head;
            ptr = ptr->next;
        } 

        ListNode* head2 = reverse(head, ptr);

        head->next = reverseKGroup(ptr,k );

        return head2;
    }
};