class Solution {
public:
    int findKthNumber(int n, int k) {
        int cur = 1;
        --k;
        while (k > 0) {
            long long steps_to_reach_neighbour = calculate_nodes_between(n, cur, cur + 1);
            if ((long long)k >= steps_to_reach_neighbour) {
                cur += 1;
                k -= steps_to_reach_neighbour;
            } else {
                cur *= 10;
                k -= 1;
            }
        }
        return cur;
    }
    
    long long calculate_nodes_between(int n, long long start, long long neighbour) {
        long long steps_to_get_to_neighbour = 0;
        while (start <= n) {
            if (n >= neighbour) {
                steps_to_get_to_neighbour += neighbour - start;
            } else {
                steps_to_get_to_neighbour += (n - start) + 1;
            }
            start *= 10;
            neighbour *= 10;
        }
        return steps_to_get_to_neighbour;
    }
};
