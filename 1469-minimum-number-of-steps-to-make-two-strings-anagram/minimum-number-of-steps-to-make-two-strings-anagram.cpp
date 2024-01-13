class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char , int> mpp1;
        unordered_map<char , int> mpp2;
        for(auto it : s)
        {
            mpp1[it]++;
        }
        for(auto it : t)
        {
            mpp2[it]++;
        }
        int ans = 0;
        for(auto it : mpp1)
        {
            // if()
            if(it.second > mpp2[it.first])
            ans+= abs(it.second - mpp2[it.first]);
        }
        return ans;
    }
};