class Solution {
public:

    bool row_check(int row,int col,int total_row,int total_col,vector<vector<int>> &mat){
        for(int i=0;i<total_col;i++){
            if(i != col && mat[row][i]!=0){
                return false;
            }
        }
        return true;
    }

    bool col_check(int row,int col,int total_row,int total_col,vector<vector<int>> &mat){
        for(int i=0;i<total_row;i++){
            if(i != row && mat[i][col]!=0){
                return false;
            }
        }
        return true;
    }

    int numSpecial(vector<vector<int>>& mat) {

        int m=mat.size();
        int n=mat[0].size();
        int count=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    if(row_check(i,j,m,n,mat) && col_check(i,j,m,n,mat)){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};