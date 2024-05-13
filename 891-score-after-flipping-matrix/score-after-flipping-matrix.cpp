class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Toggle rows
        for (int r = 0; r < rows; ++r) {
            if (grid[r][0] == 0) {
                for (int c = 0; c < cols; ++c) {
                    grid[r][c] = 1 - grid[r][c];
                }
            }
        }
        
        // Count zeroes in columns
        std::unordered_map<int, int> counts;
        for (int c = 1; c < cols; ++c) {
            for (int r = 0; r < rows; ++r) {
                if (grid[r][c] == 0) {
                    counts[c]++;
                }
            }
        }
        
        // Calculate score
        int res = rows * (1 << (cols - 1));
        for (int c = 1; c < cols; ++c) {
            res += std::max(counts[c], rows - counts[c]) * (1 << (cols - c - 1));
        }
        
        return res;
    }
};