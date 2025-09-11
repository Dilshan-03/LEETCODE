class Solution {
private:
    bool isVowel(char chr){
        char ch = tolower(chr);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    string sortVowels(string s) {
        string vowels;
        int n = s.length();
        for(int i = 0 ; i < n ; i++){
            if(isVowel(s[i])) vowels.push_back(s[i]);
        }
        sort(vowels.begin() , vowels.end());
        string t;
        int vowelPtr = 0;
        for(int i = 0 ; i < n ; i++){
           if(isVowel(s[i])){
            t.push_back(vowels[vowelPtr]);
            vowelPtr += 1;
           }
           else t.push_back(s[i]);
        }
        return t;
    }
};