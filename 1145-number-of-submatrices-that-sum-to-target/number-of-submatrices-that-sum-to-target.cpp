#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int alternative(vector<vector<int>>& matrix, int target, int n, int m){
        // Calculate prefix sums for every column
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                matrix[i][j] += matrix[i-1][j];
            }
        }
        int ans= 0; 
        for(int r0 = 0 ; r0 < n ; r0++){
            for(int r = r0 ; r < n; r++){
                unordered_map<int , int> f;
                f[0] = 1;
                int sum =0;
                for(int c = 0 ; c < m ; c++){
                    int prev=(r0==0) ? 0 : matrix[r0-1][c];
                    sum += matrix[r][c]-prev;
                    int x=sum-target;
                    ans += f.count(x) ? f[x] : 0;
                    f[sum]++;
                }
            }
        }
        return ans;
    }

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        if ( m>n ) return alternative(matrix, target, n, m);

        // Calculate prefix sums for every row
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                matrix[i][j] += matrix[i][j-1];
            }
        }
        int ans= 0; 
        for(int c0 = 0 ; c0 < m ; c0++){
            for(int c = c0 ; c < m; c++){
                unordered_map<int , int> f;
                f[0] = 1;
                int sum =0;
                for(int r = 0 ; r < n ; r++){
                    int prev=(c0==0) ? 0 : matrix[r][c0-1];
                    sum += matrix[r][c]-prev;
                    int x= sum-target;
                    ans += f.count(x) ? f[x] : 0;
                    f[sum]++;
                }
            }
        }
        return ans;
    }
};


auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();