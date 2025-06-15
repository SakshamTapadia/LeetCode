class Solution {
public:
    int maxDiff(int num) {

        string t = to_string(num);
        char c;

        bool f = false;

        for (int i = 0; i < t.size(); i++) {

            if (t[i] == '9')
                continue;

            c = t[i];
            break;
        }
        string p = to_string(num);

        for (int i = 0; i < t.size(); i++) {
            if (t[i] == c)
                t[i] = '9';
        }

        char c1 = p[0];
        for (int i = 0; i < t.size(); i++) {
            if (c1 == p[i]) {
                if (p[i] == '1')
                    continue;
                p[i] = '1';
                f = true;
            }
        }
        if (f) {
            int p1 = stoi(p);
            int p2 = stoi(t);

            cout << p1;
            return p2 - p1;
        }

        char c3;

        for (int i = 0; i < p.size(); i++) {
            if (p[i] != '0' && i != 0 && p[i]!=p[0]) {
                c3 = p[i];
                break;
            }
        }
        for (int i = 0; i < p.size(); i++) {
            if (c3 == p[i] && i!=0)
                p[i] = '0';
        }

        cout << p;

        return stoi(t) - stoi(p);
    }
};