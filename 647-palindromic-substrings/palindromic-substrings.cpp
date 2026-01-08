class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n , vector<bool>(n , false));
        int cnt = 0;
        //Len 1 strings are always palindrome
        for(int i = 0 ; i < n ; i++){
            dp[i][i] = true;
            cnt += 1;
        }

        //Check for len - 2 palindromes
        for(int i = 0 ; i < n - 1 ; i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
                cnt += 1;
            }
        }
        
        //Check for every possible length palindromes
        for(int diff = 2 ; diff < n ; diff++){
            for(int start = 0 ; start < n - diff ; start++){
                int end = start + diff;
                if(s[start] == s[end] && dp[start + 1][end - 1]){
                    dp[start][end] = true;
                    cnt += 1;
                }
            }
        }
        return cnt;
        
    }
};