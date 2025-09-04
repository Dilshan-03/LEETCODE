class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                int val = grid[i][j];
                if(i == j || i + j == n - 1){
                    if(val == 0) return false;
                }
                else if(val != 0) return false;
            }
        }
        return true;
    }
};