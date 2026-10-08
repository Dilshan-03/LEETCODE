class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int count = 0;
        string ans = "";
        for(int i = 0  ; i < n ; i++){
           char ch = s[i];
           if(ch == '('){
            if(count > 0) ans += ch;
            count++;
           }
           else{
            count--;
            if(count > 0) ans += ch;
           }
        }
        return ans;
    }
};