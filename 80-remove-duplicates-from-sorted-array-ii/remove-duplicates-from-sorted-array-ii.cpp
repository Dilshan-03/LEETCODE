class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return n;
        int i = 2 ; // Next element to placed
        int j = 2 ; // Pointer for each element's traversal
        while(j < n){
            //If the current element is not the same as element that appears before 1 element of i  , then it has to be in the i th position
            if(nums[j] != nums[i - 2]){
                nums[i] = nums[j];
                i += 1;
            }
            j += 1;
        }
        return i;
    }
};