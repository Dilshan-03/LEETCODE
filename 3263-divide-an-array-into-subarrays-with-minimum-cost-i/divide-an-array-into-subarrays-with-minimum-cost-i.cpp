class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int firstMin = 1e9 , secondMin = 1e9;
        int n = nums.size();
        for(int i = 1 ; i < n ; i++){
            if(nums[i] < firstMin){
                secondMin = firstMin;
                firstMin = nums[i];
            }
            else if(nums[i] < secondMin) secondMin = nums[i];
        }
        return (nums[0] + firstMin + secondMin);
    }
};