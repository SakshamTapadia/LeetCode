class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> count;
        int left = 0, ans = 0;

        for (int right = 0; right < tree.size(); ++right) {
            count[tree[right]]++;

            while (count.size() > 2) {
                count[tree[left]]--;
                if (count[tree[left]] == 0)
                    count.erase(tree[left]);
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
