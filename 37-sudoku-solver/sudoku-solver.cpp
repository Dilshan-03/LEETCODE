class Solution {
private:
    bool isSafe(int row , int col , char val , vector<vector<char>>& board){
        for(int i = 0 ; i < 9 ; i++){
            //checking col
            if(board[i][col] == val) return false;
            //checking row
            if(board[row][i] == val) return false;
            //checking box
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int row = 0 ; row < 9 ; row++){
            for(int col = 0 ; col < 9 ; col++){
                if(board[row][col] == '.'){
                    for(char ch = '1' ; ch <= '9' ; ch++){
                        if(isSafe(row , col , ch , board)){
                            board[row][col] = ch;
                            if(solve(board) == true) return true;
                            else board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};