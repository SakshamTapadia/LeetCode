class Solution {
public:
    unordered_map<long long, int> memo;
    int solve(int i, string& s, int mask, bool canchange, int k){
        if(i==s.size()){
            return 0;
        }
        long long key = ((long long)i<<27 | (long long)mask<<1 | (canchange ? 1LL : 0LL));

        if(memo.count(key))
            return memo[key];

        int bit = 1<<(s[i]-'a');
        int newmask = bit | mask;
        int best = 0;
        if(__builtin_popcount(newmask) > k)
            best = 1 + solve(i+1, s, bit, canchange, k);
        else
            best = solve(i+1, s, newmask, canchange, k);
        if(canchange){
            for(int c = 0; c<26;c++){
                int bit2 = 1<<c;
                int mask2 = bit2 | mask;
                int candidates;
                if(__builtin_popcount(mask2) > k)
                    candidates = 1 + solve(i+1, s, bit2, false, k);
                else
                    candidates = solve(i+1, s, mask2, false, k);
                best = max(best, candidates);
            }
        }

        memo[key] = best;
        return best;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        return 1 + solve(0, s, 0, true, k);
        

    }
};
