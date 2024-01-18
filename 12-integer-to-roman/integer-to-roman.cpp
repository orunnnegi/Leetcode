class Solution {
public:
    string intToRoman(int num) {
        vector <string> s = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        vector <int> value = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string ans = "";
        int i = value.size() - 1; 
        while (i >= 0 ) {
            if (num < value[i]) {
                i--;
            } else {
                ans += s[i];
                num -= value[i];
            }    
        }
        return ans;
    }
};