class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& nums) {
        int n= nums.size();
        int m= nums[0].size();
        vector<vector<int>> v(m, vector<int> (n, 0));
        for(int i= 0; i<n; i++){
            for(int j= 0; j<m; j++){
                v[j][i]= nums[i][j];
            }
        }
        return v;
    }
};