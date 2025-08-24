class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt = 0 ;
        int l = 0 , r = 0;
        int maxLen = 0 , n = nums.size();
        while(r < n){
            cnt += !nums[r];
            while(cnt > 1 ){
                cnt -= !nums[l];
                l++;
            }
            maxLen = max(maxLen , r - l);
            r++;
        }
        return maxLen;
    }
};