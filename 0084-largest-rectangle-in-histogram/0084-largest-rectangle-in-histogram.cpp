class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        int maxarea = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!st.empty() && heights[i] < heights[st.top()])
            {
                int val = st.top();
                st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                maxarea = max(maxarea, (nse - pse - 1) * heights[val]);
            }
            st.push(i);
        }
        while (!st.empty())
        {
            int nse = heights.size();
            int val = st.top();
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            maxarea = max(maxarea, (nse - pse - 1) * heights[val]);
        }
        return maxarea;
    }
};