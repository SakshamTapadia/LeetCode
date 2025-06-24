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
    ListNode* reverse(ListNode* head){

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* left_rev = dummy;
        ListNode* right_rev = dummy;
        ListNode* rog = dummy;
        ListNode* log = dummy;

        for(int i = 0; i < right; i++){

            if(i == left - 1) log = right_rev;
            right_rev = right_rev->next;

        }

        left_rev = log->next;
        rog = right_rev->next;

        right_rev->next = nullptr;

        ListNode* head2 = reverse(left_rev);

        log->next = head2;
        left_rev->next = rog;

        return dummy->next;
        
    }
};