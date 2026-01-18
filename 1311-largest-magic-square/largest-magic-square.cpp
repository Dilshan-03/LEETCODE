class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();
        vector<vector<int>> rowSum(m + 2 , vector<int>(n + 2, 0)) , colSum(m + 2 , vector<int>(n + 2 , 0));
        //Compute Row and column sum's prefix
        for(int i = 1 ; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                rowSum[i][j] += grid[i - 1][j - 1] + rowSum[i][j - 1];
                colSum[i][j] += grid[i - 1][j - 1] + colSum[i - 1][j];
            }
        }
        int res = 0;
        for(int i = 1; i <= m ; i++){
            for(int j = 1 ; j <= n ; j++){
                for(int k = min(m - i  , n - j ) ; k > res ; k--){
                    int sum = rowSum[i][j + k] - rowSum[i][j - 1];
                    int l = 0 , rightDiagonal = 0 , leftDiagonal = 0;
                    for(; l <= k ; l++){
                        if(sum != rowSum[i + l][j + k] - rowSum[i + l][j - 1] || sum != colSum[i + k][j + l] - colSum[i - 1][j + l]) break;
                        leftDiagonal += grid[i + l - 1][j + l - 1];
                        rightDiagonal += grid[i - 1 + k - l][j - 1 + l];
                    }
                    res = l > k && leftDiagonal == sum && rightDiagonal == sum && k > res ? k : res;
                }
            }
        }
        return res + 1;
    }
};