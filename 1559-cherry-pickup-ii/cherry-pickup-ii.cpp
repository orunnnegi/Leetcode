class Solution {
public:
    int recc(vector<vector<int>> &grid, int ind, int j1, int j2, vector<vector<vector<int>>> &v){
        int m = grid[0].size();

        if(j1<0 || j1>=m || j2<0 || j2>=m){
            return -1e9;
        }

        if(ind == grid.size()-1){
            if(j1 == j2) return grid[ind][j1];
            return grid[ind][j1] + grid[ind][j2];
        }
        if(v[ind][j1][j2] != -1){
            return v[ind][j1][j2];
        }

        int maxi =0;

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){

                int val=0;
                if(j1 == j2) val = grid[ind][j1] + recc(grid, ind+1, j1 + i, j2 + j, v);
                else val = grid[ind][j1] + grid[ind][j2] + recc(grid, ind+1, j1 + i, j2 + j, v);
                maxi = max(maxi, val);

            }
        }
        return v[ind][j1][j2] = maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        vector<vector<vector<int>>> v(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(grid[0].size(), -1)));
        return recc(grid, 0, 0, grid[0].size()-1, v);
    
    }
};