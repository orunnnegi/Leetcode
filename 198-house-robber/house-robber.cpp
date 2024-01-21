class Solution {
public:
    int helper(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i==n-1) return nums[n-1];
        if(i>=n) return 0;
        if(dp[i]!= -1) return dp[i];
        int looto=0; int nolooto= 0;
        looto= nums[i]+ helper(i+2, n, nums, dp);
        nolooto= 0+ helper(i+1, n, nums, dp);
        return dp[i]= max(looto, nolooto);

    }

    int rob(vector<int>& nums) {
            int n= nums.size();
            vector<int> dp(n, -1);
           return helper(0, n, nums, dp);
    }
};