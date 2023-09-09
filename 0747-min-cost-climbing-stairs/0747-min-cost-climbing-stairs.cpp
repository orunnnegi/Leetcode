class Solution {
public:
    int startfromzero(vector<int> &cost, int i, int n, vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        else{
            int one= cost[i]+startfromzero(cost, i+1, n, dp);
            int two= cost[i]+startfromzero(cost, i+2, n, dp);
            return dp[i]= min(one, two);
        }

    }
    int startfromone(vector<int> &cost, int i, int n, vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        else{
            int one= cost[i]+startfromone(cost, i+1, n, dp);
            int two= cost[i]+startfromone(cost, i+2, n, dp);
            return dp[i]= min(one, two);
        }
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
       int one=  startfromzero(cost, 0, n, dp1);
       int two= startfromone(cost, 1, n, dp2);
        return min(one, two);            
    }
};