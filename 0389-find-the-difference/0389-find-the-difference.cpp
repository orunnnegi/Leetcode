class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int > mpp1, mpp2;
        for(auto it: s) mpp1[it]++;
        for(auto it: t) mpp2[it]++;
        for(auto it: mpp2){
            char c= it.first;
            if(mpp1[c]==0){
                return c;
            }
            else{
                if(mpp1[c]!=mpp2[c]){
                    return c;
                }
                else continue;
            }
        }
        return ' ';
    }
};