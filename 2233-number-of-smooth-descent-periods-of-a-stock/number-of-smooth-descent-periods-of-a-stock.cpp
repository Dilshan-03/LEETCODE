class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int l = 0 , r = 0;
        int n = prices.size();
        long long cnt = 0;
        while(r < n){
            cnt += (r - l + 1);
            r += 1;
            if(r < n && prices[r] + 1 != prices[r - 1]) l = r;
        }
        return cnt;
    }
};