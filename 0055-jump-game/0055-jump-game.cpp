class Solution {
public:
    bool jump(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i==n-1) return true;
        if(i>=n) return false;
        if(dp[i]!= -1) return dp[i];
        else{
            for(int j= 1; j<=nums[i]; ++j){
                if(jump(i+j, n, nums, dp)) return dp[i]= 1;
            }
        }   
        return dp[i]=0;

    }

    bool canJump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);
        return jump(0, n, nums, dp);
    }
};