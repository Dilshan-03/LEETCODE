class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int l = 0 , r = 0;
        int n = prices.size();
        long long cnt = 0;
        while(r < n){
            cnt += (r - l + 1);
            //Increase the window size by 1 and check for valid window
            r += 1;
            //If Window is not valid , then reduce the window size to single element
            if(r < n && prices[r] + 1 != prices[r - 1]) l = r;
        }
        return cnt;
    }
};