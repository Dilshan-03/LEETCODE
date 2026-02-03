class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p = -1 , q = -1 , n = nums.size();
        int i = 1;
        //Looking for p - value in first strictly increasing half
        while(i < n - 1 && nums[i - 1] < nums[i]){
            p = i ; 
            i += 1;
        }
        if(nums[i] == nums[i - 1]) return false;
        //Looking for q - value in second strictly decreasing half
        while(i < n - 1 && nums[i - 1] > nums[i]){
            q = i;
            i += 1;
        }
        if(nums[i] == nums[i - 1]) return false;
        //Checking whether third half is strictly increasing half
        while(i < n && nums[i - 1] < nums[i]) i += 1;
        
        if(i == n && p != -1 && q != -1) return true;
        return false;
    }
};