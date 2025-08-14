class Solution {
public:
    string largestGoodInteger(string num) {
        int n = 0 , sum = 0;
        string temp = "" , ans="" ;
        for(int i = 0 ; i < num.length()-2 ; i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                n = 0;
                temp = "";
                n = n*10 + (int)(num[i]-48);
                temp += num[i];
                n = n*10 + (int)(num[i+1]-48);
                temp += num[i];
                n = n*10 + (int)(num[i+2]-48);
                temp += num[i];
                
                if(n>=sum){
                    sum = n;
                    ans = temp;
                }
            }
        }


        return ans;
    }
};