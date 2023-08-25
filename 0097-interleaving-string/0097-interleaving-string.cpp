class Solution {
private:
    int dp[101][101][201];
    bool check(int i, int j, int k, string &s1, string &s2, string &s3){
        if(k == s3.size() && i == s1.size() && j == s2.size()) return true;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int take = false;
        if(i < s1.size() && s1[i] == s3[k]){
            take |= check(i+1, j, k+1, s1, s2, s3);
        }
        if(j < s2.size() && s2[j] == s3[k]){
            take |= check(i, j+1, k+1, s1, s2, s3);
        }
        return dp[i][j][k] = take;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp, -1, sizeof(dp));
        return check(0, 0, 0, s1, s2, s3);
    }
};