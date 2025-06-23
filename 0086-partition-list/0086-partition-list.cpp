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
    ListNode* partition(ListNode* head, int x) {
        ListNode* slist = new ListNode(0, nullptr);
        ListNode* blist = new ListNode(0, nullptr);

        ListNode* small = slist;
        ListNode* big = blist;

        while(head != nullptr){

            if(head->val < x){
                ListNode* temp = new ListNode(head->val);
                small->next = temp;
                small = temp;
                
            }else{
                ListNode* temp = new ListNode(head->val);
                big->next = temp;
                big = big->next;
            }

            head = head->next;
        }

        small->next = blist->next;

        return slist->next;
        
    }
};