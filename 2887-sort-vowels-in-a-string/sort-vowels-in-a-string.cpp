class Solution {
private:
    bool isVowel(char chr){
        char ch = tolower(chr);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    string sortVowels(string s) {
        //Counting sort solution
        int n = s.length();
        vector<int> freqVowels(128 , 0);
        //Store the frequency of vowels
        for(char ch : s){
            if(isVowel(ch)) freqVowels[ch] += 1;
        }
        string sortedVowels = "AEIOUaeiou";
        string t;
        int ind = 0;
        for(int i = 0 ; i < n ; i++){
            //If vowel is encountered , in that place , put the vowels according to sorted order
            if(isVowel(s[i])){
                while(ind < sortedVowels.size() && freqVowels[sortedVowels[ind]] == 0) ind += 1;
                char ch = sortedVowels[ind];
                freqVowels[sortedVowels[ind]] -= 1;
                t.push_back(ch);
            }
            else{
                t.push_back(s[i]);
            }
        }
        return t;
        
    }
};