class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
       int n = nums.size();
       int len = 1 , maxLen = 1;
       //check for strictly increasing
       for(int i = 1 ; i < n ; i++){
            if(nums[i] > nums[i - 1]) len++;
            else len = 1;
            maxLen = max(maxLen , len);
       } 
       //Check for strinctly decreasing
       len = 1;
       for(int i = 1 ; i < n ; i++){
            if(nums[i] < nums[i - 1]) len++;
            else len = 1;
            maxLen = max(maxLen , len);
       }   
       return maxLen;

    }
};