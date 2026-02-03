class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = -1 , q = -1 , n = nums.size();
        int i = 1;
        while(i < n - 1 && nums[i - 1] < nums[i]){
            p = i ; 
            i += 1;
        }
        if(nums[i] == nums[i - 1]) return false;
        while(i < n - 1 && nums[i - 1] > nums[i]){
            q = i;
            i += 1;
        }
        if(nums[i] == nums[i - 1]) return false;

        while(i < n && nums[i - 1] < nums[i]) i += 1;
        if(i < n) return false;
        if(p != -1 && q != -1) return true;
        return false;
    }
};