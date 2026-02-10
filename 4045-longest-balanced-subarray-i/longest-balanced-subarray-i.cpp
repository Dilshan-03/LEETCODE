class Solution {
public:
    int longestBalanced(vector<int>& nums) {
      int n = nums.size();
      int len = 0;
      for(int i = 0 ; i < n ; i++){
        unordered_set<int>oddNumbers , evenNumbers;
        for(int j = i ; j < n ; j++){
            if(nums[j] % 2 == 0) evenNumbers.insert(nums[j]);
            else oddNumbers.insert(nums[j]);
            if(oddNumbers.size() == evenNumbers.size()) len = max(len , j - i + 1);
        }
      }
      return len;   
    }
};