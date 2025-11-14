class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> hashMap(26 , 0);
        for(char ch : s){
            if(hashMap[ch - 'a']) return ch;
            hashMap[ch - 'a'] += 1;
        }
        //Just what if there is no character that appers twice
        return ' ';
    }
};