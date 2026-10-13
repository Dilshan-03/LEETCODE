class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size(),i;
        for(int i = 0 ; i < n ; i++) nums[i] = abs(nums[i]);
        nth_element(nums.begin() , nums.begin() + n / 2 , nums.end());

        long long sum = 0;
        
        for( i = 0 ; i < n / 2 ; i++) sum -= (nums[i] * nums[i]);
        for(; i < n ; i++) sum += (nums[i] * nums[i]);
        
        return sum;
    }
};