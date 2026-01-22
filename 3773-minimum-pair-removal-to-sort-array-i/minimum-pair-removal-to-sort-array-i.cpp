class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int cnt = 0;
        while(1){
            int ind = 0 , mini = 1e9;
            bool isNonDecrease = true;
           for(int i = 0 ; i < nums.size() - 1 ; i++){
              int sum = (nums[i] + nums[i + 1]);
              if(sum < mini){
                mini = sum;
                ind = i;
              }
              if(nums[i] > nums[i + 1]) isNonDecrease = false;
            }
            if(isNonDecrease) return cnt;
            nums[ind] = mini;
            nums.erase(nums.begin() + ind + 1);
            cnt += 1;
        }
        return 0;
    }
};