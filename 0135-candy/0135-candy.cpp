class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        int given = 0;
        vector<int> candies(n);

        int min_ele = *min_element(ratings.begin(), ratings.end());
                
        for(int i = 0; i < ratings.size(); ++i){
            if(ratings[i] == min_ele){
                candies[i] = 1;
                ++given;
            }
        }

        while(given < n){
            for(int i = 0; i < n; ++i){
                
                if(candies[i]) continue;
                
                int candy = 1;
                
                if(i == 0 || ratings[i] <= ratings[i-1]){
                }else if(candies[i-1] != 0){
                    candy = max(candy, candies[i-1]+1);
                }else{
                    continue;
                }
                
                
                if(i == n-1 || ratings[i] <= ratings[i+1]){
                }else if(candies[i+1] != 0){
                    candy = max(candy, candies[i+1]+1);
                }else{
                    continue;
                }
                
                candies[i] = candy;
                ++given;
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};