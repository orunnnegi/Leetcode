class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vis[r][c] = 1; // Marking the cell as visited
        int drow[] = {0, -1, 0, 1};
        int dcol[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            // Check if the neighboring cell is within bounds, unvisited, and is 'O'
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, board); // Recursively visit neighboring 'O' cells
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return; // Edge case: empty board
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Initialize visit matrix
        
        // Traverse the first and last row
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && board[0][i] == 'O') {
                dfs(0, i, vis, board); // DFS from border 'O' cells
            }
            if (!vis[n - 1][i] && board[n - 1][i] == 'O') {
                dfs(n - 1, i, vis, board); // DFS from border 'O' cells
            }
        }
        
        // Traverse the first and last column
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && board[i][0] == 'O') {
                dfs(i, 0, vis, board); // DFS from border 'O' cells
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O') {
                dfs(i, m - 1, vis, board); // DFS from border 'O' cells
            }
        }
        
        // Now, any 'O' that is not visited is surrounded by 'X', update the board accordingly
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X'; // Surrounded 'O'
                }
            }
        }
    }
};
