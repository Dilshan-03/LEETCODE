class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = 0;
        int sum = 0 , len = 1e9;
        while(r < n ){
            sum += nums[r];
            while(sum >= target){
                len = min(len , r - l + 1);
                sum -= nums[l];
                l += 1;
            }
            r += 1;
        }
        return len == 1e9 ? 0 : len;
    }
};