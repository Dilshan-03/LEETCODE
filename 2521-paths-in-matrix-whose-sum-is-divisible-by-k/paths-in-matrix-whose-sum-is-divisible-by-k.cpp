class Solution {
private:
    int mod = (int) 1e9 + 7;
    int helper(int row , int col , int sum , vector<vector<int>>& grid , vector<vector<vector<int>>>& dp ,  int k , int n , int m){
        if(row == n || col == m) return 0;
        if(row == n - 1 && col == m - 1) return ((sum + grid[row][col]) % k) ? 0 : 1 ; 
        if(dp[row][col][(sum + grid[row][col]) % k] != -1) return dp[row][col][(sum + grid[row][col]) % k]; 
        int down = helper(row + 1 , col , sum + grid[row][col], grid , dp , k , n , m );
        int right = helper(row , col + 1 , sum + grid[row][col], grid , dp ,  k , n , m);
        return dp[row][col][(sum + grid[row][col]) % k] = (down + right) % mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n  , vector<vector<int>>(m , vector<int>(k , -1)));
        return helper(0 , 0 , 0 , grid, dp , k , n , m);
       

       /* for(int row = n - 2 ; row >= 0 ; row --){
            for(int col = m - 1 ; col >= 0 ; col--){
                for(int sum = 0 ; sum < k ; sum++){
                    int down = dp[row + 1][col][(sum + grid[row][col]) % k];
                    int right = dp[row][col + 1][(sum + grid[row][col]) % k];
                    dp[row][col][(sum + grid[row][col])% k] = (down + right) % mod;
                }
            }
        }
        return dp[0][0][0];*/
        
    }
};