class Solution {
public:
    int longestContinuousSubstring(string s) {
       int n = s.length();
       int len = 1 , maxLen = 1;
       for(int i = 1 ; i < n ; i++){
            if(s[i]  ==  s[i - 1] + 1) len += 1;
            else len = 1;
            maxLen = max(maxLen , len);
       } 
       return maxLen;
    }
};