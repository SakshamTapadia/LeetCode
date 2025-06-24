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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        vector<int>v;
        vector<int>nums;
        while(head){
            nums.push_back(head->val);
            head=head->next;
        }
        int i=1,j=0;
        while(j<nums.size()){
            vector<int>v1;
            if(i%2==1){
                for(int k=1;k<=i;k++){
                    if(j<nums.size()) v1.push_back(nums[j++]);
                   
                }
            }
            else{
                
                for(int k=1;k<=i;k++){
                    if(j<nums.size()) v1.push_back(nums[j++]);
                    
                }
                
            }
            if(v1.size()%2==0){
                reverse(v1.begin(),v1.end());
                for(auto u:v1){
                    v.push_back(u);
                }
            }
            else{
                for(auto u:v1){
                    v.push_back(u);
                }
            }
            i++;
        }

        ListNode *root=NULL,*current=NULL;
        for(auto u:v){
            ListNode *tem=new ListNode(u);
            if(root==NULL){
                root=tem;
                current=tem;
            }
            else{
                current->next=tem;
                current=current->next;
            }
        }
        return root;
    }
};