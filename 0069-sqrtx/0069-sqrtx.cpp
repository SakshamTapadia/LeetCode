class Solution 
{
public:
    int mySqrt(int x) 
    {
        int left = 0;
        int right = x >> 1; 

        if(x < 2)
            return x;
        
        while(left <= right){
            long mid = (left + right) >> 1;   
            if(mid * mid == x)
                return mid;
            else if(mid * mid < x)
                left = mid + 1;
            else
                right = mid - 1; 
        }
        return left - 1;
    }
};
