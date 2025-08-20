class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans = 0;
        int maxi = *max_element(nums.begin() , nums.end());
        int l = 0 , r = 0 , n = nums.size();
        int cnt = 0;
        while(r < n){
            if(nums[r] == maxi) cnt++;
            //Whenever , the window contains atleast k elements , add the answer and shrink the window
            while(cnt >= k){
                ans = ans + (n - r);
                if(nums[l] == maxi) cnt--;
                l++;
            }
            r++;
        }
        return ans;
    }
};