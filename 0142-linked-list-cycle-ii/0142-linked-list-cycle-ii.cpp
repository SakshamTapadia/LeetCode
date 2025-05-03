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
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL) return 0;
        ListNode* f=head,*s=head,*t=head;
        while(f->next && f->next->next){
            f=f->next->next;
            s=s->next;
            if(f==s){
                while(t!=f) {f=f->next;t=t->next;}
                return f;
            }
        }
        return NULL;
    }
};