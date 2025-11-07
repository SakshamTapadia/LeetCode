class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        long long left = 0;
        long long right = accumulate(stations.begin(), stations.end(), 0LL) + k;
        long long ans = 0;
        while (left <= right) {
            long long mid = (left + right) / 2;
            if (isGood(stations, r, mid, k)) {
                ans = mid; 
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        return ans;
    }

    bool isGood(vector<int>& stations, int r, long long minPowerRequired, int additionalStations) {
        int n = stations.size();
        long long windowPower = accumulate(stations.begin(), stations.begin()+r, 0LL);
        vector<int> additions(n, 0);
        for (int i = 0; i < n; i++) {
            if (i + r < n) {
                windowPower += stations[i + r];
            }
            if (windowPower < minPowerRequired) {
                long long needed = minPowerRequired - windowPower;
                if (needed > additionalStations) {
                    return false;
                }
                additions[min(n - 1, i + r)] += needed;
                windowPower = minPowerRequired;
                additionalStations -= needed;
            }
            if (i - r >= 0) {
                windowPower -= stations[i - r] + additions[i - r];
            }
        }
        return true;
    }
};