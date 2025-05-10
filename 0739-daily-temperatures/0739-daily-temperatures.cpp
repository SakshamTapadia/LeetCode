class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int> ans(n);
        int hottest = 0;

        for(int i = n-1; i>=0; i--){
            if(t[i]>=hottest){
                hottest = t[i];
            }
            else{
                int days = 1;
                while(t[i+days]<=t[i]){
                    days = days+ans[i+days];
                }
                ans[i] = days;
            }
        }

        return ans;
    }
};