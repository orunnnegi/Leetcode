class Solution {
public:

    int minJumps(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i>=n-1) return 0;
        if(dp[i]!= -1) return dp[i];
        long long ans= INT_MAX;
        for(int j= 1; j<= nums[i]; j++){
            long long jump = 1ll* 1+minJumps(i+j, n, nums, dp);
            ans= min(jump, ans);
        }
        return dp[i]=  ans;
    }

    int jump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);
        return minJumps(0, n, nums, dp);
    }
};