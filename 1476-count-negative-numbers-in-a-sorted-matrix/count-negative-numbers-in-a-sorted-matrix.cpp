class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        int row = 0 , col = m - 1;
        int cnt = 0;
        while(row < n && col >= 0){
            //If the current element is negative , anyway every elements below it also negative , just count them and shrink down the column
            if(grid[row][col] < 0){
                cnt += (n - row);
                col -= 1;
            }
            //If the current element is non-negative , evey element to the left of it also non - negative , so move to next row
            else row += 1;
        }
        return cnt;
        //TC : O(n + m)
        //SC : O(1)
    }
};