class Solution {
public:

    int helper(int ind, int size, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if(ind == size)
        {
            return 0;
        }
        if(dp[ind][amount] != -1)
        {
            return dp[ind][amount];
        }
        if(amount == 0)
        {
            return 1;
        }

        int pick = 0;
        int unpick = 0;
        if(amount >= coins[ind])
        {
            pick = helper(ind, size, coins, amount - coins[ind], dp);
        }
        unpick = helper(ind + 1, size, coins, amount, dp);
        return dp[ind][amount] = pick + unpick;
    }

    int change(int amount, vector<int>& coins) {
        int size = coins.size();
        vector<vector<int>> dp(size, vector<int>(amount + 1, -1));
        return helper(0, size, coins, amount, dp);
    }
};