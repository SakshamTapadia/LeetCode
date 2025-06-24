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
    ListNode* reverseList(ListNode* head, ListNode* end){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != end){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        int groupSize = 1;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* preGroupTail = &dummy;
        ListNode* cur = head;

        while(cur){
            int cnt = 0;
            ListNode* groupHead = cur;
            ListNode* tmp = cur;
            while(cnt < groupSize && tmp){
                tmp = tmp->next;
                cnt++;
            }
            ListNode* nextGroupHead = tmp;

            if(cnt % 2 == 0){
                ListNode* newGroupHead = reverseList(groupHead, nextGroupHead);
                preGroupTail->next = newGroupHead;
                groupHead->next = nextGroupHead;
                preGroupTail = groupHead;
            }else{
                preGroupTail = cur;
                for(int i = 1; i < cnt; i++){
                    preGroupTail = preGroupTail->next;
                }
            }
            cur = nextGroupHead;
            groupSize++;
        }

        return dummy.next;
    }
};