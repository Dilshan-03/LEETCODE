class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int maxLen = 0 , open = 0 , close = 0;
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '(') open += 1;
            else close += 1;
            if(open == close) maxLen = max(maxLen , 2 * open);
            else if(close > open) open = close = 0;
        }

        open = close = 0;  
        for(int i = n - 1 ; i > 0 ; i--){
            if(s[i] == '(') open += 1;
            else close += 1;
            if(open == close) maxLen = max(maxLen , 2 * open);
            else if(close < open) open = close = 0;
        }
        return maxLen;
    }
};