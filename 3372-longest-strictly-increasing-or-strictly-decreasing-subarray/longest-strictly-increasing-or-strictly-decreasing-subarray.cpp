class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
       int n = nums.size();
       int len = 0 , maxLen = 0;
       bool isIncrease = true;
       //check for strictly increasing
       for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i] < nums[i + 1]){
                if(isIncrease) len += 1;
                else{
                    len = 1;
                    isIncrease = true;
                }
            } 
            else if(nums[i] > nums[i + 1]){
                if(!isIncrease) len += 1;
                else{
                    len = 1;
                    isIncrease = false;
                }
            }
            else len = 0;
            maxLen = max(maxLen , len);
       } 
   
       return maxLen + 1;

    }
};