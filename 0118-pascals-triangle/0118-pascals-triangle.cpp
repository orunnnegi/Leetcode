class Solution {
public:
    vector<vector<int>> generate(int n) {
        int i=0;
        vector<vector<int>> ans(n);
        while(i<n){
             ans[i].resize(i + 1);
            for(int j=0;j<=i/2;j++){
                if(j==0){
                ans[i][j]=1;
                ans[i][i-j]=1;
                }
                else{
                    ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
                    ans[i][i-j]=ans[i][j];
                }
            }
            i++;
        }
        return ans;
    }
};