class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int size = s.size();
        int c = count(s.begin(), s.end(), '1');
        // int remain = size - c;
        // cout << c;
        string ans(size, '0');
        for(int ind = 0; ind < c - 1; ind++)
        {
            ans[ind] = '1';
        }
        ans[size - 1] = '1';
        // return c;
        return ans;
    }
};