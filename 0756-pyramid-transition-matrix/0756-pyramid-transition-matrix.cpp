class Solution {
public:
    map<string,vector<string>> mp;
    map<string,bool> dp;
    bool solve(int ind, string newlayer, string oldlayer, int n)
    {
        if(n==1) return true;
        
        if(ind==n-1)
        {
            if (dp.count(newlayer)) return dp[newlayer];
            return dp[newlayer]=solve(0,"",newlayer,n-1);
        }
        string tmp = oldlayer.substr(ind,2);

        if(!mp.count(tmp)) return false; 
        for(auto x:mp[tmp]){
            if(solve(ind+1,newlayer+x,oldlayer,n))
                return true;
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        
        int n = bottom.size();


        for(auto x:allowed){
            mp[x.substr(0,2)].push_back(x.substr(2));
        }

        return solve(0,"",bottom,n);
    }
};