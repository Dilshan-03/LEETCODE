class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int prevCnt = 0;
        long long cnt = 0;
        //Store the previous cnt of zeros for calculating that subarray math
        for(int i = 0 ; i < n ; i++){
           if(nums[i] == 0) {
            cnt += (prevCnt + 1);
            prevCnt++;
           }
           else prevCnt = 0;
        }
        return cnt;
    }
};