class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n= s.length();
        set<char> st;
        int l= 0; int r= 0;
        int ans= 0;
        while(r<n){
            if(find(st.begin(), st.end(), s[r])==st.end()){
                ans= max(ans, r-l+1);
                st.insert(s[r]);
                r++;
                continue;
            }
            else{
                st.erase(s[l]);
                l++;
                continue;
            }
        }
        return ans;
    }
};