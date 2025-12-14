class Solution {
private:
    int mod = (int)1e9 + 7;
    int f(int i , int cnt ,int n ,  string& corridor , vector<vector<int>>& dp){
        if(i == n || cnt > 2){
            return (cnt == 2);
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        if(corridor[i] == 'S'){
            if(cnt + 1 == 2) return dp[i][cnt] = (f(i + 1 , 0 , n , corridor , dp) + f(i + 1 , cnt + 1 , n , corridor , dp)) % mod;
            else if(cnt + 1 < 2) return dp[i][cnt] = f(i + 1 , cnt + 1 , n , corridor , dp) % mod;
            return 0;
        }
        else{
            if(cnt == 2) return dp[i][cnt] = (f(i + 1 , 0 , n , corridor , dp) + f(i + 1 , cnt , n , corridor , dp)) % mod;
            else return dp[i][cnt] = f(i + 1 , cnt , n , corridor , dp) % mod;
        }
    }
public:
    int numberOfWays(string corridor) {
        int n = corridor.length();
        vector<vector<int>> dp(n + 1 , vector<int>(4 , 0));
        //return f(0 , 0 , n , corridor , dp);
        dp[n][2] = 1;
        for(int i = n - 1 ; i >= 0 ; i--){
            for(int cnt = 2 ; cnt >= 0 ; cnt--){
              if(corridor[i] == 'S'){
                if(cnt + 1 == 2) dp[i][cnt] = (dp[i + 1][0] + dp[i + 1][cnt + 1]) % mod;
                else if(cnt + 1 < 2) dp[i][cnt] = dp[i + 1][cnt + 1] % mod;
                else dp[i][cnt] = 0;
              }
              else{
                if(cnt == 2) dp[i][cnt] = (dp[i + 1][0] + dp[i + 1][cnt]) % mod;
                else  dp[i][cnt] = dp[i + 1][cnt] % mod;
               }
            }
        }
    return dp[0][0];
    }
};