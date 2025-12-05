class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        long fact = 1;
        for(int i=1; i<n; i++){
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k = k-1;
        string ans = "";
        while(true){
            int idx = k/fact;
            ans.append(to_string(numbers[idx]));
            numbers.erase(numbers.begin() + idx);
            k = k % fact;
            if(k==0) break;
            fact = fact/numbers.size();
        }

        for(int i=0; i<numbers.size(); i++){
            ans.append(to_string(numbers[i]));
        }

        return ans;
    }
};