class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n = text.length();
        vector<int> freq(26 , 0);
        //Store the broken Letters in hashMap for effective retrival
        for(char ch : brokenLetters) freq[ch - 'a'] += 1;
        int i = 0;
        int words = 0; 
        while(i < n){
            bool canType = true;
            //Go through entire word and check whether it contains broken letters
            while(i < n && text[i] != ' '){
                if(freq[text[i] - 'a']) canType = false;
                i++;
            }
            //If broken letters are not there , then take the current word into account
            if(canType)  words += 1;
            //Move to next word
            i += 1;
        }
        return words;
    }
};