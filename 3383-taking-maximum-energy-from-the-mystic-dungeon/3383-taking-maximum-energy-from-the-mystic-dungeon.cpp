class Solution {
public:
    int maximumEnergy(vector<int>& vals, int k) {
        for (int i = vals.size() - k - 1; i >= 0; --i)
        {
            vals[i]  += vals[i+k];
        }
        return *max_element(vals.begin(), vals.end());
    }
};