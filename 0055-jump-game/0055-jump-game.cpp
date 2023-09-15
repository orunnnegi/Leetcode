class Solution
{
    public:
        bool fun(int i, int n, vector<int> &nums, vector<int> &dp)
        {
            if (i == n - 1) return true;
            if (i > n) return true;
            if (dp[i] != -1) return dp[i];
            else
            {
                for (int j = 1; j <= nums[i]; j++)
                {
                    if (fun(i + j, n, nums, dp))
                    {
                        return dp[i] = true;
                    }
                }
            }
            return dp[i] = false;
        }

    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return fun(0, n, nums, dp);
    }
};