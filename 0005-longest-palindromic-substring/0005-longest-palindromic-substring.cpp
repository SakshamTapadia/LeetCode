class Solution{
public:
    vector<int> manachers_algo(string s){
        string newS = "#";
        for(char c: s){
            newS += string(1, c) + "#";
        }
        int n = newS.size();
        vector<int> arrLPS(n, 0);
        int l = 0, r = 0;
        for(int i = 0; i < n; i++){
            if(r - i > 0) arrLPS[i] = min(r-i, arrLPS[l + r - i]);

            while(i-arrLPS[i]-1 >= 0 && i+arrLPS[i]+1 < n && newS[i-arrLPS[i]-1]==newS[i+arrLPS[i]+1]){
                arrLPS[i]++;
            }
            if(i+arrLPS[i] > r){
                l = i - arrLPS[i];
                r = i + arrLPS[i];
            }
        }
        return arrLPS;
    }

    string longestPalindrome(string s){
        vector<int> arrLPS = manachers_algo(s);
        int maxLPS = arrLPS[0];
        int center = 0;
        for(int i = 1; i < arrLPS.size(); i++){
            if(arrLPS[i] > maxLPS){
                maxLPS = arrLPS[i];
                center = i;
            }
        }
        int beginIndex = (center-maxLPS)/2;
        return s.substr(beginIndex, maxLPS);
    }
};