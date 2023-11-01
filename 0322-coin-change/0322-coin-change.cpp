class Solution {
public:
    int fun(int i, int n, vector<int> &v, int k, vector<vector<int>> &dp){
        if(i>=n) return 1e5;
        if(dp[i][k]!=-1) return dp[i][k];
        if(k==0) return 0;
        int pick= 1e5, unpick= 1e5;
        if(v[i]<=k){
            pick= 1+fun(i, n, v, k-v[i], dp);
        }
        unpick= fun(i+1, n, v, k, dp);
        return dp[i][k]= min(pick, unpick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        int ans= fun(0, n, coins, amount, dp);
        return ans==1e5?-1:ans;
    }
};