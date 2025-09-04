class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int row = 0 , col1 = 0 , col2 = n - 1;
        int sum = 0;
        while(row < n){
            sum += mat[row][col1];
            if(col1 != col2) sum += mat[row][col2];
            row += 1;
            col1 += 1;
            col2 -= 1;
        }
        return sum;
    }
};