class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int row = 0 , col  = n - 1;
        vector<vector<int>> sortedDiagonalGrid(n , vector<int>(n , 0));
        bool flag = false;
        while(row < n){
            int nrow = row  , ncol = col;
            vector<int> diagonal;
            while(nrow < n && ncol < n){
                diagonal.push_back(grid[nrow][ncol]);
                nrow += 1;
                ncol += 1;
            }
            if(row == 0 && col == 0) flag = true;
            if(!flag) sort(diagonal.begin() , diagonal.end());
            else sort(diagonal.begin() , diagonal.end() , greater<int>());

            nrow = row , ncol = col;
            int i = 0;
            while(nrow < n && ncol < n){
                sortedDiagonalGrid[nrow][ncol] = diagonal[i];
                nrow += 1;
                ncol += 1;
                i += 1;
            }
            if(col > 0) col -= 1;
            else row = row += 1;
        }
        return sortedDiagonalGrid;
    }
};