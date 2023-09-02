class Solution {
public:
    void transpose(vector<vector<int>> &v, int n, int m){
        for(int i= 0; i<n; ++i){
            for(int j= i+1; j<n; ++j){
                swap(v[i][j], v[j][i]);
            }
        }
        // for(int i= 0; i<n; i++){
        //     for(int j= 0; j<m; j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // return; 
    }

    void rotate(vector<vector<int>>& v) {
        int n= v.size(); int m= v[0].size();
        transpose(v,n, m);
        for(int i= 0; i<n; i++){
            for(int j= 0; j<m/2; ++j){
                swap(v[i][j], v[i][m-j-1]);
            }
        }
    }
};