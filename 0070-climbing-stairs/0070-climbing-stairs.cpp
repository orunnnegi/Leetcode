class Solution
{
    public:
        int countways(int n, vector<int> &dp)
        {
            if(n<=2) return n;
            if (dp[n] != -1) return dp[n];
            else
            {
                int one = countways(n - 1, dp);
                int two = countways(n - 2, dp);
                return dp[n] = one + two;
            }
        }

    int climbStairs(int n)
    {
        vector<int> dp(n + 1, -1);
        return countways(n, dp);
    }
};