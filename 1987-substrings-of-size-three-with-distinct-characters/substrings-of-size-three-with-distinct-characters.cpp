class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        vector<int> hashMap(26 , 0);
        int l = 0 , r = 0;
        int cnt = 0;
        while(r < n){
            hashMap[s[r] - 'a'] += 1;
            while((r - l + 1 > 3) || (hashMap[s[r] - 'a'] > 1)){
                hashMap[s[l] - 'a'] -= 1;
                l += 1;
            }
            if(r - l + 1 == 3) cnt += 1;
            r += 1;
        }
        return cnt;
    }
};