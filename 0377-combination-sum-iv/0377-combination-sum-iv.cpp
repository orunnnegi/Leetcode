class Solution {
public:
    vector<int>dp;
    vector<int>nums;
    int target;
    int DP(int tar){
        if(tar == 0) return 1;
        if(tar < 0) return 0;
        if(dp[tar] != -1) return dp[tar];
        int take = 0;
        for(int i = 0; i < nums.size(); i++){
            take += DP(tar - nums[i]);
        }
        return dp[tar] = take;
        
    }
    int combinationSum4(vector<int>& nums, int target) {
        this->nums = nums;
        this->target = target;
        dp.resize(target + 1, -1);
        return DP(target);
    }
};