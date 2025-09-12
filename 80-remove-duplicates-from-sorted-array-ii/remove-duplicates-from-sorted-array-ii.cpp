class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0 , k = 0;
        while(i < n){
            int j = i + 1;
            while(j < n && nums[j] == nums[i]) j += 1;
            if(j - i >= 2){
                nums[k] = nums[k + 1] = nums[i];
                k += 2;
            }
            else{
                nums[k] = nums[i];
                k += 1;
            }
            i = j;
        }
        return k;
    }
};