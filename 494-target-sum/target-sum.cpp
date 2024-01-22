class Solution {
public:

    int helper(int ind , int size, int k, vector<int> &nums)
    {
        if(ind == size)
        {
            if(k == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int plus = 0;
        int minus = 0;
        plus = helper(ind + 1, size, k - nums[ind], nums);
        minus = helper(ind + 1, size, k + nums[ind], nums);
        return plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        return helper(0, size, target , nums);
    }
};