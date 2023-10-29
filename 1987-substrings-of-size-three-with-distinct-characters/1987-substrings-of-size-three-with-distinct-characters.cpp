class Solution {
public:
    int countGoodSubstrings(string s) {
        int k = 3;
        int ans= 0;
        int n= s.length();
        if(n<k) return ans;
        map<char , int> mpp;
        bool flag= true;
        for(int i= 0; i<k ;i++){
            mpp[s[i]]++;

        }
        for(auto it: mpp){
            if(it.second>1){
                flag= false;
                break;
            }
        }
        if(flag) ans++;
        int j= 0;
        
        for(int i= k; i<n; i++){
            mpp[s[j++]]--;
            mpp[s[i]]++;
            bool ff= true;
            for(auto it: mpp){
                if(it.second>1){
                    ff= false;
                    break;
                }
            }
            if(ff) ans++;

        }
        return ans;
    }
};