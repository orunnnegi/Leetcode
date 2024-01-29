class Solution {
public:




    int helper(int ind, int size, vector<int> &nums, int target)
    {
        if(ind == size)
        {
            if(target == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int add = 0;
        int minus = 0;
        add = helper(ind + 1, size, nums, target - nums[ind]);
        minus = helper(ind + 1, size, nums, target + nums[ind]);
        return add + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        return helper(0, size, nums, target);
    }
};