class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mpp1;
        map<char, int> mpp2;
        for(auto it: s) mpp1[it]++;
        for(auto it: t) mpp2[it]++;
        return mpp1==mpp2;
    }
};