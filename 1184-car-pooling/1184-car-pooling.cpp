class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for (auto x : trips) {
            int passengers = x[0];
            int left = x[1];
            int right = x[2];

            diff[left] += passengers;
            diff[right] -= passengers;
        }

        int current = 0;
        for (int x : diff) {
            current += x; 
            if (current > capacity) return false;
        }

        return true;
    }
};
