class Solution {
public:
    int minOperations(string s) {
        int n= s.size();
        int ans= 0;
        for(int i= 0 ; i<n-1; i++){
            if(s[i]==s[i+1]) {ans++; s[i+1]= s[i]=='0'? '1': '0';}
        }
        
        return ans>(n/2)?abs(ans-n):ans;
    }
};