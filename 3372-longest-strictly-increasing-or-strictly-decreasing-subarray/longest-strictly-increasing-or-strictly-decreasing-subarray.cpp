class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
       int n = nums.size();
       int len = 0 , maxLen = 0;
       bool isIncrease = true;
       for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i] < nums[i + 1]){
                //If already in increasing half  , then just update the len by 1
                if(isIncrease) len += 1;
                //if not already in increasing half , then just put the len as 1 for the current element and make it as increasing
                else{
                    len = 1;
                    isIncrease = true;
                }
            } 

            else if(nums[i] > nums[i + 1]){
                 //If already in decreasing half  , then just update the len by 1
                if(!isIncrease) len += 1;
                //if not already in decreasing half , then just put the len as 1 for the current element and make it as decreasing
                else{
                    len = 1;
                    isIncrease = false;
                }
            }
            else len = 0;
            maxLen = max(maxLen , len);
       } 
       
       //To compensate for final element and initially taking len as 1
       return maxLen + 1;

    }
};