class Solution {
private:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int l = 0 , r = 0;
        int cnt = 0 , maxNum = 0;
        while(r < n){
            //Trim down the window whenever it becomes size > k
            if(r - l + 1 > k){
                if(isVowel(s[l])) cnt--;
                l++;
            }
            if(isVowel(s[r])) cnt++;
            maxNum = max(maxNum , cnt);
            r++;
        }
        return maxNum;
    }
};