class Solution {
public:
    string intToRoman(int num) {
        string roman[4];
        string ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string thousands[10] = {"", "M", "MM", "MMM"};
        roman[3] = ones[num % 10];
        num /= 10;
        roman[2] = tens[num % 10];
        num /= 10;
        roman[1] = hundreds[num % 10];
        num /= 10;
        roman[0] = thousands[num % 10];        
        for(int i = 1; i <= 3; i++)
            roman[0].append(roman[i]);

        return roman[0];
    }
};