class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k >= num.size()) return "0";
        
        stack<int> stk;
        
        for(int i = 0; i < num.size(); i++){
            while(k > 0 && !stk.empty() && stk.top() > num[i]){
                stk.pop();
                k--;
            }
            stk.push(num[i]);
        }
        while(k-- > 0){
            stk.pop();
        }
        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        while(ans.size() > 1 && ans[0] == '0'){
            ans.erase(0, 1);
        }
        
        return ans;
    }
};