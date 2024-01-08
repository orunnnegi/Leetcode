class Solution {
public:

    void markRowZeroes(int i, int j, vector<vector<int>> &matrix, int n, int m)
    {
        for(int k = 0; k< m; k++)
        {
            if(matrix[i][k] != 0)
            {
                matrix[i][k] = -9999999;
            }
        }
        return;
    }

    void markColumnZeroes(int i, int j, vector<vector<int>> &matrix, int n, int m)
    {
        for(int k= 0; k<n; k++)
        {
           if(matrix[k][j] != 0)
           {
               matrix[k][j] = -9999999;
           }
        }
        return;
    }


    void setZeroes(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m= matrix[0].size();
        // brute force
        for(int i = 0; i < n; i++)
        {
            for(int j= 0; j< m; j++)
            {
                if(matrix[i][j] == 0)
                {
                    markRowZeroes(i , j , matrix, n, m);
                    markColumnZeroes(i, j, matrix, n, m);
                }
            }
        }
        for(int i= 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] == -9999999)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        return;
           
    }
};