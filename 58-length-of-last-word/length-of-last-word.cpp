class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        int len = 0;
        int i = n - 1;
        //Remove extra white spaces at the end
        while(i >= 0 && s[i] == ' ') i--;

        //Count the length of last Word
        while(i >= 0 && s[i] != ' '){
            len += 1;
            i -= 1;
        }
        return len;
    }
};