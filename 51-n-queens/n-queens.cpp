class Solution {
public:


    bool isSafe(int row, int col, vector<string> board, int size)
    {
        int duprow = row;
        int dupcol = col;
        while(duprow >= 0 and dupcol >= 0)
        {
            if(board[duprow][dupcol] == 'Q')
            {
                return false;
            }
            duprow--;
            dupcol--;
        }
        duprow = row;
        dupcol = col;
        while(dupcol >= 0)
        {
            if(board[duprow][dupcol] == 'Q')
            {
                return false;
            }
            dupcol--;
        }
        duprow = row;
        dupcol = col;
        while(duprow < size and dupcol >= 0)
        {
            if(board[duprow][dupcol] == 'Q')
            {
                return false;
            }
            dupcol--;
            duprow++;
        }
        return true;
    }

    void solve(int ind , int size, vector<string> &board, vector<vector<string>> &NQueens)
    {
        if(ind == size)
        {
            NQueens.push_back(board);
            return;
        }
        for(int row = 0; row < size; row++)
        {
            if(isSafe(row, ind, board, size) == true)
            {
                board[row][ind] = 'Q';
                solve(ind + 1, size, board, NQueens);
                board[row][ind] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> NQueens;
        string s(n, '.');
        vector<string> board(n, s);
        solve(0, n, board, NQueens);
        return NQueens;
    }
};