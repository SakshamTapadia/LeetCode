class Solution {
    void f(int num, vector<int>& ds) {
        while (num > 0) {
            ds.push_back(num % 10);
            num /= 10;
        }
    }

public:
    int minMaxDifference(int num) {
        int c = -1;
        vector<int> ds;
        f(num, ds);
        reverse(ds.begin(), ds.end());

        int a = ds[0]; 
        string as = "", bs = "";

        
        for (int i : ds) {
            if (i != 9) {
                c = i;
                break;
            }
        }

        
        for (int i = 0; i < ds.size(); i++) {
            if (ds[i] == c)
                as += '9';
            else
                as += to_string(ds[i]);
        }

      
        for (int i = 0; i < ds.size(); i++) {
            if (a != 0 && ds[i] == a)
                bs += '0';
            else
                bs += to_string(ds[i]);
        }

        return stoi(as) - stoi(bs);
    }
};