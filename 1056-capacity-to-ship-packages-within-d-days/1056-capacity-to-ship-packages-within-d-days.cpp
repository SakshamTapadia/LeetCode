class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(weights, mid, days)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool isValid(vector<int>& weights, int capacity, int days) {
        int currentLoad = 0;
        int requiredDays = 1;

        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                requiredDays++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }

        return requiredDays <= days;
    }
};