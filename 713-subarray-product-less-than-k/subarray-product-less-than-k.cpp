class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1;
        int l = 0 , r = 0;
        int n = nums.size();
        int cnt = 0;
        while(r < n){
            prod *= nums[r];
            while(l <= r && prod >= k){
                prod /= nums[l];
                l += 1;
            }
            cnt += (r - l + 1);
            r += 1;
        }
        return cnt;
    }
};