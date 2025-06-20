class Solution {
public:
        bool possible(vector<int>& weights, int capacity, int days) {
        int dayCount = 1;
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                dayCount++;   
                currentLoad = 0;
            }
            currentLoad += w;
        }

        return dayCount <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;

        while(low <=high){
            int mid = low+(high-low)/2;

            if(possible(weights,mid,days)){
                high = mid-1;
                ans = mid;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }
};