class Solution {
public:
    int minNumberOperations(vector<int>& target) {
       int prev=target[0];
      int ans=target[0];
       for(int i=1;i<target.size();i++){
        int curr=target[i];
        if(curr<=prev){
            prev=curr;
        }
        else{
            ans+=curr-prev;
            prev=curr;
        }
       } 
       return ans;
    }
};