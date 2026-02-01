class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int firstMin = 1e9 , secondMin = 1e9;
        int n = nums.size();
        //Finding 1 st and 2 nd minimum numbers from the array excluding 1 st element of array
        for(int i = 1 ; i < n ; i++){
            if(nums[i] < firstMin){
                secondMin = firstMin;
                firstMin = nums[i];
            }
            else if(nums[i] < secondMin) secondMin = nums[i];
        }
        //Since subarry is asked , nums[0] can surely be the first element of 1 subarray and accordingly other minimum elements can be taken as other 2 subarrays first element
        return (nums[0] + firstMin + secondMin);
    }
};