class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin() , nums.end() , 0);
        if(totalSum < target) return 0;
        int l = 0 , r = 0;
        int sum = 0 , len = n ;
        while(r < n ){
            sum += nums[r];
            while(l < r && sum > target){
                len = min(len , r - l + 1);
                sum -= nums[l];
                l += 1;
            }
            if(sum >= target) len = min(len , r - l + 1);
            r += 1;
        }
        return len;
    }
};