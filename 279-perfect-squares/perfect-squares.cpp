class Solution {
public:
    int helper(int i , int n, int target, vector<int> &v, vector<vector<int>> &dp){
        if(i>=n) return 1e5;
        if(dp[i][target]!= -1) return dp[i][target];
        if(target==0){
            return 0;
        }
        int pick= 1e5, notpick= 1e5;
        if(v[i]<=target){
            pick = 1+ helper(i, n, target-v[i], v, dp);
        }
        notpick= helper(i+1, n, target, v, dp);
        return dp[i][target]= min(pick, notpick);
    }

    int numSquares(int n) {
        vector<int> v;
        int i= 1;
        while(i*i<=n){
            v.push_back(i*i);
            i++;
        }
        i--;
        // cout<<i<<endl;
        // for(auto it: v) cout<<it<<" ";
        vector<vector<int>> dp(i+1, vector<int>(n+1, -1));
        return helper(0, i, n, v, dp);
    }
};