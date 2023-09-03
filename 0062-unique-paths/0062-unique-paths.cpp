class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<int> dp(n+1, 0);
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 and j == n-1){
                    dp[j] = 1;
                    continue;
                }
                dp[j] = dp[j+1] + dp[j];
            }
        }
        return dp[0];
    }
};