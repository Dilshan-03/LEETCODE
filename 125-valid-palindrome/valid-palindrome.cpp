class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0 , r = n - 1;
        while(l < r){
            //Skip the characters which are not alphanumeric
            while(l < r && !isalnum(s[l])) l += 1;
            while(l < r && !isalnum(s[r])) r -= 1;
            //After skipping , check if the alphanumeric characters are equal
            if(tolower(s[l]) != tolower(s[r])) return false;
            l += 1;
            r -= 1;
        }
        return true;
    }
};