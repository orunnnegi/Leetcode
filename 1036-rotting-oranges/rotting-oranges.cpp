class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int , int>, int>> bfs;
        int time = INT_MIN;
        vector<vector<int>> vis(n , vector<int> (m , 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    vis[i][j] = 2;
                    bfs.push({{i , j}, 0});
                }
            }
        }
        int delRow[] = {0 , - 1 , 0, +1};
        int delCol[] = {-1 , 0 , +1 , 0};
        while(bfs.empty() == false)
        {
            int row = bfs.front().first.first;
            int col = bfs.front().first.second;
            int currTime = bfs.front().second;
            bfs.pop();
            time = max(time , currTime);
            for(int k = 0; k < 4; k++)
            {
                int nRow = row + delRow[k];
                int nCol = col + delCol[k];
                if(nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and vis[nRow][nCol] == 0 and grid[nRow][nCol] == 1)
                {
                    bfs.push({{nRow, nCol}, currTime+1});
                    vis[nRow][nCol] = 2;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                if(grid[i][j] == 1 and vis[i][j] == 0)
                {
                    return -1;
                }
            }
        }
        return time == INT_MIN ? 0 : time ;
    }
};