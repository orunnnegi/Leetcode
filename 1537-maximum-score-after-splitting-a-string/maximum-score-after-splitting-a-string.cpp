class Solution {
public:
    int maxScore(string s) {
        int n= s.size();
        int one= count(s.begin(), s.end(), '1');
        int zero=0;
        int ans= -1;
        for(int i= 0 ;i< n-1; i++){
            if(s[i]=='1'){
                one--;
            }
            else{
                zero++;
            }
            ans= max(ans, zero+one);
        }
        return ans;
    }
};