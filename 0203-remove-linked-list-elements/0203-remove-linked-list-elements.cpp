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
    ListNode* removeElements(ListNode* head, int target) {

        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr && curr->val == target){
            head = curr->next;
            delete(curr);
            curr = head;
        }

        while(curr){

            if(curr->val == target){
                prev->next = curr->next;
                delete(curr);
                curr = prev->next;
            }else{
                prev = curr;
                curr = curr->next;
            }
        }

        return head;
        
    }
};