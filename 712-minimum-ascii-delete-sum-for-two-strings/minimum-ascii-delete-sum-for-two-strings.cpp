class Solution {
private:
    int f(int i , int j , string& s1 , string&s2 , vector<vector<int>>& dp){
        if(i == 0){
            int totalAscii = 0;
            for(int k = 0 ; k < j ; k++) totalAscii += s2[k];
            return totalAscii;
        }
        if(j == 0){
            int totalAscii = 0;
            for(int k = 0 ; k < i ; k++) totalAscii += s1[k];
            return totalAscii;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i - 1] == s2[j - 1]) return dp[i][j] = f(i - 1 , j - 1 , s1 , s2 , dp);
        return dp[i][j] = min(s1[i - 1] + f(i - 1 , j, s1 , s2 , dp) , s2[j - 1] + f(i , j - 1 , s1 , s2 , dp));
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length() , m = s2.length();
        vector<vector<int>> dp(n + 1  , vector<int>(m + 1 , 0));

        //Base case for i == 0
        for(int j = 1 ; j <= m ; j++){
            int totalAscii = 0;
            for(int k = 0 ; k < j ; k++) totalAscii += s2[k];
            dp[0][j] = totalAscii;
        }
        //Base case for j == 0
        for(int i = 1 ; i <= n ; i++){
            int totalAscii = 0;
            for(int k = 0 ; k < i ; k++) totalAscii += s1[k];
            dp[i][0] = totalAscii;
        }

        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(s1[i - 1] + dp[i - 1][j] , s2[j - 1] + dp[i][j - 1]);
            }
        }
        return dp[n][m];

    }
};