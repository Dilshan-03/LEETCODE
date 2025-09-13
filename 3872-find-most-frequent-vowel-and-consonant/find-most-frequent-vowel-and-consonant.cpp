class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    int maxFreqSum(string s) {
        vector<int> freq(26 , 0);
        int n = s.length();
        int maxVowelFreq = 0 , maxConsFreq = 0;
        for(int i = 0 ; i < n ; i++){
            freq[s[i] - 'a'] += 1;
            if(isVowel(s[i])) maxVowelFreq = max(maxVowelFreq , freq[s[i] - 'a']);
            else maxConsFreq = max(maxConsFreq , freq[s[i] - 'a']);
        }
        return (maxVowelFreq + maxConsFreq);
    }
};