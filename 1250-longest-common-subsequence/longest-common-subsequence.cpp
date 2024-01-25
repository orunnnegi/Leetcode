class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int n= t1.length(), m= t2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0)) ;
        for(int i= 1; i<m+1; i++){
            for(int j= 1; j<n+1; j++){
                if(t2[i-1]== t1[j-1]){
                    dp[i][j]= dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};