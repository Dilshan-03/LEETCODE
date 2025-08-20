class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int last = n - 1;
        int front = 0;
        //last is the pointer , which points to non - val elements
        while(front <= last){
            //If the val is occurred both at the front and back too , we can just reduce the last pointer by 1
            if(nums[front] == val && nums[last] == val){
                last--;
                continue;
            }
            //If the val is occurred only at the front , we can just swap it with last 
            else if(nums[front] == val){
                swap(nums[front] , nums[last]);
                last--;
            }
            front++;
        }
        //For the cnt , we can return last + 1
        return last + 1;
    }
};