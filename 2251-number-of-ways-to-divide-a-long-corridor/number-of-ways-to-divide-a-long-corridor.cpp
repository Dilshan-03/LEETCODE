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
        vector<vector<int>> dp(n , vector<int>(3 , -1));
        return f(0 , 0 , n , corridor , dp);
    }
};