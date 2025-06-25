class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;
        int i = -1;
        int n = tickets.size();

        while (tickets[k] != 0) {
            i++;
            if (i == n) i = 0; 

            if (tickets[i] > 0) tickets[i]--; 
            else continue;
            
            time++;        
        }

        return time;
    }
};
