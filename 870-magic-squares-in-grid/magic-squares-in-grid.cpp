class Solution {
private:
    bool isMagicSquare(vector<vector<int>>& grid , int i , int j){
        vector<int> hashMap(10 , 0);
        for(int row = i ; row < i + 3 ; row++){
            for(int col = j ; col < j + 3 ; col++){
                if(grid[row][col] > 9 || grid[row][col] == 0) return false;
                else{
                    hashMap[grid[row][col]] += 1;
                    if(hashMap[grid[row][col]] > 1) return false;
                }
            }
        }
        int r1 = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
        int r2 = grid[i + 1][j] + grid[i + 1][j + 1] + grid[i + 1][j + 2];
        int r3 = grid[i + 2][j] + grid[i + 2][j + 1] + grid[i + 2][j + 2];
        int c1 = grid[i][j] + grid[i + 1][j] + grid[i + 2][j];
        int c2 = grid[i][j + 1] + grid[i + 1][j + 1] + grid[i + 2][j + 1];
        int c3 = grid[i][j + 2] + grid[i + 1][j + 2] + grid[i + 2][j + 2];
        int ld = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
        int rd = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];
        return (r1 == r2 && r2 == r3 && r3 == c1 && c1 == c2 && c2 == c3 && c3 == ld && ld == rd);
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i = 0 ; i <= (n - 3) ; i++){
            for(int j = 0 ; j <= (m - 3) ; j++){
                if(isMagicSquare(grid , i , j)) cnt += 1;
            }
        }
        return cnt;
    }
};