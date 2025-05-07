class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> v(n+1, 0);
        for(auto& i : bookings)
        {
            v[i[0] - 1] += i[2];
            v[i[1]] -= i[2];
        }

        vector<int> res;
        res.push_back(v[0]);
        for(int i=1;i<n;i++) res.push_back(res.back() + v[i]);
        return res;
    }
};