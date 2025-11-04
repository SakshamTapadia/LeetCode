class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for(int i = 0; ;) {
            if(++i < colors.size() && colors[i] != colors[i - 1]) {
                continue;
            } else if(i >= colors.size()) {
                break;
            }

            int max_time = max(neededTime[i], neededTime[i - 1]);
            int total = neededTime[i] + neededTime[i - 1];
            while(++i < colors.size() && colors[i] == colors[i - 1]) {
                max_time = max(max_time, neededTime[i]);
                total += neededTime[i];
            }
            ans += total - max_time;
        }
        return ans;
    }
};