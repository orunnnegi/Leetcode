class Solution {
public:
    int helper(int ind , int size, vector<int> &coins, int target, vector<vector<int>> &dp)
    {
        if(ind == size)
        {
            return 1e6;
        }
        if(dp[ind][target] != -1)
        {
            return dp[ind][target];
        }
        if(target == 0)
        {
            return 0;
        }
        int pick = 1e6;
        int notPick = 1e6;
        if(coins[ind] <=  target)
        {
            pick = 1 + helper(ind , size, coins, target - coins[ind], dp);
        }
        notPick = 0 + helper(ind + 1, size, coins, target, dp);
        return dp[ind][target] = min(pick , notPick);
    }

    int coinChange(vector<int>& coins, int amount) {
        int size = coins.size();
        vector<vector<int>> dp(size, vector<int>(amount + 1, -1));
        sort(coins.begin() , coins.end(), greater<int>());
        int ans = helper(0, size, coins, amount, dp);
        return ans == 1e6 ? -1 : ans;
    }
};