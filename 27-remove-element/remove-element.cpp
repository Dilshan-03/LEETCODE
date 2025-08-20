class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int last = n - 1;
        int front = 0;
        while(front <= last){
            if(nums[front] == val && nums[last] == val){
                last--;
                continue;
            }
            else if(nums[front] == val){
                swap(nums[front] , nums[last]);
                last--;
            }
            front++;
        }
        return last + 1;
    }
};