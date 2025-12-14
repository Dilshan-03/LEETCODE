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
        //return f(0 , 0 , n , corridor , dp);
        vector<int> next(3 , 0);
        next[2] = 1;
        for(int i = n - 1 ; i >= 0 ; i--){
            vector<int> cur(3 , 0);
            for(int cnt = 2 ; cnt >= 0 ; cnt--){
              if(corridor[i] == 'S'){
                if(cnt + 1 == 2) cur[cnt] = (next[0] + next[cnt + 1]) % mod;
                else if(cnt + 1 < 2) cur[cnt] = next[cnt + 1] % mod;
              }
              else{
                if(cnt == 2) cur[cnt] = (next[0] + next[cnt]) % mod;
                else  cur[cnt] = next[cnt] % mod;
               }
            }
            next = cur;
        }
    return next[0];
    }
};