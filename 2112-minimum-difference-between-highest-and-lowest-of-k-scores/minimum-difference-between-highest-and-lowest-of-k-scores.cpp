class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int mini = INT_MAX;
        int n = nums.size();
        for(int i = 0 ; i <= n - k ; i++){
            int low = nums[i];
            int high =  nums[i + k - 1];
            mini = min(mini , high - low);
        }
        
        return mini;
    }
};