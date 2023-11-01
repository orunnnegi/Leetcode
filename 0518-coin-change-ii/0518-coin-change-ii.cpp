class Solution {
public:

    int allCombinations(int i, int n, int k, vector<int> &v, vector<vector<int>> &dp){
        if(i>=n) return 0;
        if(dp[i][k]!= -1) return dp[i][k];
        if(k==0) return 1;
        int pick= 0, notpick= 0;
        if(v[i]<=k){
            pick= allCombinations(i, n, k-v[i], v, dp);
        }
        notpick= allCombinations(i+1, n, k, v, dp);
        return dp[i][k]= pick+ notpick;
    }

    int change(int k, vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        int ans= allCombinations(0, n, k, nums, dp);
        return ans;


    }
};