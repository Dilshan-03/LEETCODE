class Solution {
private:
    int mod = (int) 1e9 + 7;
    int helper(int row , int col , int sum , vector<vector<int>>& grid , vector<vector<vector<int>>>& dp ,  int k , int n , int m){
        if(row == n || col == m) return 0;
        if(row == n - 1 && col == m - 1) return ((sum + grid[row][col]) % k) ? 0 : 1 ; 
        sum = sum + grid[row][col];
        if(dp[row][col][sum % k] != -1) return dp[row][col][sum % k]; 
        int down = helper(row + 1 , col , sum , grid , dp , k , n , m );
        int right = helper(row , col + 1 , sum , grid , dp ,  k , n , m);
        return dp[row][col][sum % k] = (down + right) % mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n , vector<vector<int>>(m , vector<int>(k , -1)));
        return helper(0 , 0 , 0 , grid, dp , k , n , m);
    }
};