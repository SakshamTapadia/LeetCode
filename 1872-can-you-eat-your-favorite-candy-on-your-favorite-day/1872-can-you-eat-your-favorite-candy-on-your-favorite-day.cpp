class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int m = candiesCount.size();
        int n = queries.size();

        vector<long long> prefix(m + 1, 0); 
        for (int i = 0; i < m; i++) {
            prefix[i + 1] = prefix[i] + candiesCount[i];
        }

        vector<bool> result;
        for (const auto& q : queries) {
            int type = q[0];
            int day = q[1];
            int cap = q[2];

            long long minCandies = day + 1;                     
            long long maxCandies = (long long)(day + 1) * cap;  

            long long earliestCandy = prefix[type] + 1; 
            long long latestCandy = prefix[type + 1];   
            if (maxCandies >= earliestCandy && minCandies <= latestCandy) {
                result.push_back(true);
            } else {
                result.push_back(false);
            }
        }

        return result;
    }
};