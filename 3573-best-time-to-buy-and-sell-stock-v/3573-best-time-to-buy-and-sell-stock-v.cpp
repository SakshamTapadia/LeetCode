struct Data{
    long long profit=0, buy=0, sell=0;
    Data(long long profit=0, long long buy=0, long long sell=0):
        profit(profit), buy(buy), sell(sell) {}
};
class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const int x0=prices[0];
        vector<Data> dp(k+1, Data(0, -x0, x0));// day 0
        const int n=prices.size();
        for(int i=1; i<n; i++){
            const int x=prices[i];
            for(int t=k; t>0; t--){
                auto& [p, b, s]=dp[t];
                const long long prevP=dp[t-1].profit;
                p=max(p, max(b+x, s-x));
                b=max(b, prevP-x);
                s=max(s, prevP+x);
            }
        }
        return dp[k].profit;
    }
};