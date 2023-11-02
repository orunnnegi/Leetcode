class Solution {
public:

    int helper(int i, int n, vector<int> &nums, int target, int sum){
        if(i== n && sum!= target) return 0;
        if(i==n && sum==target) return 1;
        int plus= 0;
        int minus= 0;
        plus= helper(i+1, n, nums, target, sum+nums[i]);
        minus = helper(i+1, n, nums, target, sum-nums[i]);
        return plus+minus;

    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n= nums.size();
        return helper(0, n, nums, target, 0);

    }
};