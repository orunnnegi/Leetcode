class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        map<char, int> mpp;
        int l= 0; int r= 0;
        int ans= 0;
        while(r<n){
            if(mpp[s[r]]==0){
                mpp[s[r]]++;
                ans= max(ans, r-l+1);
                r++;
            }
            else{
                mpp[s[l]]= 0;
                l++;
            }
        }
        return ans;
    }
};