class Solution {
private:
    bool checkIsAvailable(int row , int col , char ch , vector<vector<char>>& board){
        for(int i = 0 ; i < 9 ; i++){
            if(i != col && board[row][i] == ch) return true;
            if(i != row && board[i][col] == ch) return true;
            int nrow = 3 * (row / 3) + i / 3;
            int ncol = 3 * (col / 3) + i % 3;
            if(nrow != row && ncol != col && board[nrow][ncol] == ch) return true; 
        }
        return false;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] != '.' && checkIsAvailable(i , j , board[i][j] , board)) return false;
            }
        }
        return true;
    }
};