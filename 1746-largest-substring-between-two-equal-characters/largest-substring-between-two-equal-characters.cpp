class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> f(26,-1);
        int ans = -1;
        for(int i=0;i<s.size();i++){
            if(f[s[i]-'a']!=-1){
                ans = max(ans,i-f[s[i]-'a']-1);
            }
            else  f[s[i]-'a']=i;
        }
        return ans;
    }
};