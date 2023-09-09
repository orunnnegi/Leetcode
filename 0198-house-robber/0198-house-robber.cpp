class Solution {
public:
    int robber(vector<int> &nums, int i, vector<int> &dp){
        if(i==0) return nums[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        else{
            int rob= nums[i]+robber(nums, i-2, dp);
            int notrob= robber(nums, i-1, dp);
            return dp[i]= max(rob, notrob);
        }
    }

    int rob(vector<int>& nums) {
        int n= nums.size();

        vector<int> dp(n, -1);
        return robber(nums, n-1, dp);
    }
};