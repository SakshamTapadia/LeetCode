#define mod 1000000007
class Solution {
public:
    int numberOfWays(string corridor) {
        int seats = 0;
        int plants = 0;
        long long ways = 1;
        for(int i = 0;i  < corridor.size(); i++){
            if(corridor[i] == 'S'){
                ways = (ways * (plants + 1)) % mod;
                plants = 0;
                seats += 1;

            }
            else if(seats != 0 && seats%2 == 0){
                plants += 1;
            }
        }
        if(seats == 0 || seats % 2 != 0){
            return 0;
        }
        return (int)ways;
    }
};