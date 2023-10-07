#define M 1000000007

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (k+1, -1)));
        function<int(int, int, int)> helper = [&](int i, int prev_max, int curr_k){
            if(curr_k<0) return 0;
            if(i==n){
                if(curr_k==0) return 1;
                return 0;
            }
            
            if(dp[i][prev_max][curr_k]!=-1) return dp[i][prev_max][curr_k];
            
            int ans{};
            for(int j = 1; j <= m; ++j){
                if(j<=prev_max){
                    ans = ((ans%M) + (helper(i+1, prev_max, curr_k))%M)%M;
                }
                else{
                    ans = ((ans%M) + (helper(i+1, j, curr_k-1))%M)%M;
                }
            }

            return dp[i][prev_max][curr_k] = ans;

        };

        return helper(0, 0, k);

    }
};