class Solution {
public:
    bool isAnagram(string s, string t) {
        // map<char, int> mpp1;
        // map<char, int> mpp2;
        // for(auto it: s) mpp1[it]++;
        // for(auto it: t) mpp2[it]++;
        // return mpp1==mpp2;

        vector<int> a1(26, 0), a2(26, 0);
        for(char it: s){int t= it-97; a1[t]++;}
        for(char it: t){int t= it-97; a2[t]++;}
        // for(auto it: a1) cout<<it<<" ";
        return a1==a2;
    }
};