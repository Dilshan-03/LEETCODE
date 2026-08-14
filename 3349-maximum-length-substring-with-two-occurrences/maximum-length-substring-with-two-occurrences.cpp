class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>hashMap(26,0);
        int l = 0 , r = 0 , n = s.length();
        int maxLen = 0;
        while(r < n){
            hashMap[s[r] - 'a'] += 1;
            while(hashMap[s[r] - 'a'] > 2){
                hashMap[s[l] - 'a'] -= 1;
                l += 1;
            }
            maxLen = max(maxLen, r - l + 1);
            r += 1;
        }
        return maxLen;
    }
};