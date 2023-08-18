class Solution {
private:
    bool issafe(int row,int col,vector<vector<char>> &board,char ch){
    int n=board.size();
    for(int i=0;i<n;i++){
        // row check
        if(board[row][i]==ch && i != col){
            return false;
        }
        // column check
        if(board[i][col]==ch && i != row){
            return false;
        }
        // 3*3 matrix check
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch &&row!=(3*(row/3)+i/3) && (3*(col/3)+i%3)!=col){
            return false;
        }
    } 
    return true;
}
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    bool val=issafe(i,j,board,board[i][j]);
                    if(val==false){
                        return false;
                    }
                }
            }
        }
        return true; 
    }
};