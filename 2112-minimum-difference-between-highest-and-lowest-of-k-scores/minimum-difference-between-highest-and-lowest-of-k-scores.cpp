class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        //Group the similar values together to minimise the difference
        sort(nums.begin() , nums.end());
        int mini = INT_MAX;
        int n = nums.size();
        //Create a window of size k and check for all possible differences
        for(int i = 0 ; i <= n - k ; i++){
            int low = nums[i];
            int high =  nums[i + k - 1];
            mini = min(mini , high - low);
        }
        
        return mini;
    }
};