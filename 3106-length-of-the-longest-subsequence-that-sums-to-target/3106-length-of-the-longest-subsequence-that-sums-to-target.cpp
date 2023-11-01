class Solution {
public:
    int recur(int i, int n , vector<int> &v, int k, vector<vector<int>> &dp){
        if(k==0) return 0;
        if(i>=n) return INT_MIN;
        if(dp[i][k]!=-1) return dp[i][k];
        
        int pick = INT_MIN, unpick= INT_MIN;
        if(v[i]<=k){
            pick= 1+recur(i+1, n, v, k-v[i], dp);
        }
        unpick= recur(i+1, n, v, k, dp);
        return dp[i][k]= max(pick, unpick);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> dp(n+1, vector<int> (target+1, -1));
        int ans= recur(0, n, nums, target, dp);
        cout<<ans;
        return ans<=0?-1: ans;
    }
};