class Solution {
public:
    int robber(int i, int n, vector<int> &nums, vector<int> &dp){
        if(i==n) return nums[i];
        if(i>n) return 0;
        if(dp[i]!= -1) return dp[i];
        else{
            int rob= nums[i]+robber(i+2, n, nums, dp);
            int leave= robber(i+1, n, nums, dp);
            return dp[i]= max(rob, leave);
        }
    }


    int rob(vector<int>& nums) {
        int n= nums.size();

        if(n==1) return nums[0];
        vector<int> dp(n, -1);
        vector<int> pp(n, -1);
        int firstChoice= robber(0, n-2, nums, dp);
        int secondChoice= robber(1, n-1, nums, pp);
        return max(firstChoice, secondChoice);

    }
};