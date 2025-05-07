class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> seats(n,0);
        for(auto &it: bookings){
            int first = it[0];
            int last = it[1];
            int seat = it[2];

            for(int i = first-1 ; i <= last-1 ;i++){
                seats[i] += seat;
            }
        }
        return seats;
    }
};