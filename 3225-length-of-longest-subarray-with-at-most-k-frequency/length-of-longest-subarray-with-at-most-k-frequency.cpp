class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 , r = 0 , len = 0;
        unordered_map<int , int> freqMap;
        while(r < n){
            freqMap[nums[r]] += 1;
            while(freqMap[nums[r]] > k){
                freqMap[nums[l]] -= 1;
                l += 1;
            }
            len = max(len , r - l + 1);
            r += 1;
        }
        return len;
    }
};