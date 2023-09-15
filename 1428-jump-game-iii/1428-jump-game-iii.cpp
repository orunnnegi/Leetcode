class Solution {
public:
    bool jump(int i, int n, vector<int> &nums, vector<int> &dp, vector<bool> &vis){
        if(nums[i]==0) return true;
        // if(i==0 && nums[i]!=0) return dp[i]= 0;
        // if(i==n-1 && nums[i]!=0) return dp[i]= 0;
        if(dp[i]!=-1) return dp[i];
        else{
            int forward= i+nums[i], backward= i-nums[i];
            if(forward<n && vis[forward]==false){
                vis[forward]= true;
                if(jump(forward, n, nums, dp, vis)) return dp[i]= 1;
            }
            if(backward>=0 && vis[backward]==false){
                vis[backward]= true;
                if(jump(backward, n, nums, dp, vis)) return dp[i]= 1;
            }

        }
        return dp[i]=0;
    }

    bool canReach(vector<int>& arr, int start) {
        int n= arr.size();
        vector<bool> vis(n, false);
        vector<int> dp(n, -1);
        return jump(start, n, arr, dp, vis);
    }
};