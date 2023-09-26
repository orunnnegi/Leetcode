class Solution {
public:

    string removeOtherCharacters(string s, int n){
        string ans;
        for(int i= 0; i<n; i++){
            if(isalnum(s[i])){
                ans.push_back(tolower(s[i]));
            }
        }
        return ans;
    }

    bool isPalindrome(string s) {
        int n= s.length();
        string ans= removeOtherCharacters(s, n);
        // cout<<ans;
        int  len= ans.length();
        for(int i= 0; i<len/2; i++){
            if(ans[i]!= ans[len-i-1]) return false;
        }
        return true;
    }
};