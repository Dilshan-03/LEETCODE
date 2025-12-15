class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;
        int cnt = 0 , ind = 0;
        int prevDiff = nums[1] - nums[0];
        for(int r = 1 ; r < n - 1 ; r++){
            int diff= nums[r + 1] - nums[r];
            if(diff != prevDiff){
                prevDiff = diff;
                ind = 0;
            }
            else ind += 1;
            cnt += ind;
        }
        return cnt;
    }
};