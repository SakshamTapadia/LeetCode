class Solution {
public:
    int bestClosingTime(string customers) {
        int curPenalty = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (customers[i] == 'Y') {
                curPenalty++;
            }
        }
        int minPenalty = curPenalty;
        int earliestHour = 0;

        for (int i = 0; i < customers.size(); ++i) {
            char ch = customers[i];

            if (ch == 'Y') {
                curPenalty--;
            } else {
                curPenalty++;
            }
            if (curPenalty < minPenalty) {
                earliestHour = i + 1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    }
};