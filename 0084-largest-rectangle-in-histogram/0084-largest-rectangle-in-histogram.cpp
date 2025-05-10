class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int ans = 0;
        heights.push_back(0);
        
        for(int i = 0; i < heights.size(); i++){
            while(!stk.empty() && heights[i] < heights[stk.top()]){
                int cur = stk.top(); stk.pop();
                ans = max(ans, heights[cur] * (stk.empty() ? i : (i- 1 - stk.top())));
            }
            stk.push(i);
        }
        
        return ans;
    }
};