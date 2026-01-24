class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int minMaxSum = 0;
        int l = 0 , r = n - 1;
        while(l < r){
            //Balancing the weights
            int sum = nums[l] + nums[r];
            minMaxSum = max(minMaxSum , sum);
            l += 1;
            r -= 1;
        }
        return minMaxSum;
        
    }
};