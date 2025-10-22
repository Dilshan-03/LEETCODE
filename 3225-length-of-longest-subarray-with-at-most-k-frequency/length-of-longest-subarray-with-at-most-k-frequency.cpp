class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 , r = 0 , len = 0;
        unordered_map<int , int> freqMap;
        while(r < n){
            freqMap[nums[r]] += 1;
            //Whenever current window has elements greater than frequency of k , shrink it
            while(freqMap[nums[r]] > k){
                freqMap[nums[l]] -= 1;
                l += 1;
            }
            //Calculate the length 
            len = max(len , r - l + 1);
            r += 1;
        }
        return len;
        //TC : O(2N)
        //SC : O(N) -> Frequency array
    }
};