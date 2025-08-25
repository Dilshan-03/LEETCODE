class Solution {
private:
    void backtrack(int col , vector<int>& leftRow , vector<int>& leftDiagonal , vector<int>& rightDiagonal , vector<string>& board , int n , int& cnt){
        if(col == n){
            cnt++;
            return;
        }
        
        for(int row = 0 ; row < n ; row++){
            if(board[row][col] == '.' && !leftRow[row] && !leftDiagonal[n - 1 + col - row] && !rightDiagonal[row + col]){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                leftDiagonal[n - 1 + col - row] = 1;
                rightDiagonal[row + col] = 1;
                backtrack(col + 1 , leftRow , leftDiagonal , rightDiagonal , board , n , cnt);
                board[row][col] = '.';
                leftRow[row] = 0;
                leftDiagonal[n - 1 + col - row] = 0;
                rightDiagonal[row + col] = 0;
            }
        }

    }
public:
    int totalNQueens(int n) {
        vector<int> leftRow(n , 0);
        vector<int> leftDiagonal(2 * n - 1 , 0) , rightDiagonal(2 * n - 1 , 0);
        string temp(n , '.');
        vector<string> board(n , temp);
        int cnt = 0;
        backtrack(0 , leftRow , leftDiagonal , rightDiagonal , board , n , cnt);
        return cnt;
    }
};