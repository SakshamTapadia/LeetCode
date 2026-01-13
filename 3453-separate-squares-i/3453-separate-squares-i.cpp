class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = -1e9;

        for (auto &sq : squares) {
            double B = sq[1], L = sq[2];
            low = min(low, B);
            high = max(high, B + L);
        }

        auto diff = [&](double y) -> double {
            double difference = 0;
            for (auto &sq : squares) {
                double B = sq[1], L = sq[2], t = B + L;
                if (y <= B) {
                    difference += L * L;  
                } else if (y >= t) {
                    difference -= L * L;  
                } else {
                    difference += L * ((t + B) - 2 * y);  
                }
            }
            return difference;
        };

        while (high - low > 1e-6) { 
            double mid = (low + high) / 2.0;
            if (diff(mid) > 0)
                low = mid; 
            else
                high = mid; 
        }

        return (low + high) / 2.0;  
    }
};