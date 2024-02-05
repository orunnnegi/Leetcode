class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        unordered_map<char , int> mpp;
        for(auto it: s)
        {
            mpp[it]++;
        }
        for(int ind = 0; ind < size; ind++)
        {
            if(mpp[s[ind]] == 1)

            {
                return ind;
            }
        }
        return -1;
    }
};