class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==k)return "0";
        int n=num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() &&k&&  st.top()>num[i]){
                st.pop();k--;
            }
            st.push(num[i]);
        }
        while(k-- && !st.empty()) st.pop();
        if(st.empty())return "0";
        string res="";
        while(!st.empty()){res+=st.top();st.pop();}
        while(!res.empty() && res.back()=='0')res.pop_back() ;

        reverse(res.begin(),res.end());
        if(res.empty())return "0";
        else return res;
   }
};