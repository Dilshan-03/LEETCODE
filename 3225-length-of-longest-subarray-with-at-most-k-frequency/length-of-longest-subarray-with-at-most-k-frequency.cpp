class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0 , r = 0 , len = 0;
        int charWithfreqMorethanK = 0;
        unordered_map<int , int> freqMap;
        //Rather than exploring all the good subarrays , as we only need longest good subarray , we can just keep track of longest good subarray with exploring all good subarray
        while(r < n){
            freqMap[nums[r]] += 1;
            //Whenever char occurs more than k times in the window , mark it
            if(freqMap[nums[r]] == k + 1) charWithfreqMorethanK += 1;
            //Shrink the window , if it contains bad element , anyway we trim by 1 step , therefore maintaining the previous good subarray's length , if it becomes good , then we can expand 
            if(charWithfreqMorethanK){
                freqMap[nums[l]] -= 1;
                if(freqMap[nums[l]] == k) charWithfreqMorethanK -= 1;
                l += 1;
            }
            r += 1;
        }
        return n - l;
        //TC : O(N)
        //SC : O(N) -> Frequency array
        
    }
};