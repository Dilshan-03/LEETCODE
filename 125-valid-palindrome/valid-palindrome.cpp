class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0 , r = n - 1;
        while(l < r){
            while(l < r && !isalnum(s[l])) l += 1;
            while(l < r && !isalnum(s[r])) r -= 1;
            if(isalnum(s[l]) && isalnum(s[r])){
                char leftChar = tolower(s[l]);
                char rightChar = tolower(s[r]);
                if(leftChar != rightChar) return false;    
            }
            l += 1;
            r -= 1;
        }
        return true;
    }
};