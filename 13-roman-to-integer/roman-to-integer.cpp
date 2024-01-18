class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        int num = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(mpp[s[i]] >= mpp[s[i+1]])
            {
                num+= mpp[s[i]];
            }
            else
            {
                num-= mpp[s[i]];
            }
        }
        return num;
    }
};