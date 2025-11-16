class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        int l = 0 , r = 0 ;
        int cnt = 0 , mod = (int)(1e9 + 7);
        while(r < n){
            if(s[r] == '0') l = r + 1;
            else cnt = (cnt + (r - l + 1)) % mod;
            r += 1;
        }
        return cnt;
    }
};