class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0)
            return "0";        

        string fraction;
        if ((numerator < 0) ^ (denominator < 0))
            fraction += "-";        

        long long dividend = llabs((long long)numerator);
        long long divisor = llabs((long long)denominator);
        fraction += to_string(dividend / divisor);
        long long remainder = dividend % divisor;
        if (remainder == 0) {
            return fraction;
        }

        fraction += ".";
        unordered_map<long long, int> map;
        while (remainder != 0) {
            if (map.count(remainder)) {
                fraction.insert(map[remainder], "(");
                fraction += ")";
                break;
            }
            map[remainder] = fraction.size();
            remainder *= 10;
            fraction += to_string(remainder / divisor);
            remainder %= divisor;
        }

        return fraction;
    }
};