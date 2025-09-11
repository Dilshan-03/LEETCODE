class Solution {
private:
    bool isVowel(char ch){
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    string reverseVowels(string s) {
        int n = s.length();
        int l = 0 , r = n - 1;
        while(l < r){
            while(l < r && !isVowel(s[l])) l += 1;
            while(l < r && !isVowel(s[r])) r -= 1;
            swap(s[l] , s[r]);
            l += 1;
            r -= 1;
        }
        return s;
    }
};