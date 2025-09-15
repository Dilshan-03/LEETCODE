class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i = 0 ; i < n ; i++) st.insert(nums[i]);
        int k = st.size();
        int cnt = 0;
        unordered_map<int , int> mpp;
        int l = 0 , r = 0;
        while(r < n){
            mpp[nums[r]] += 1;
            while(mpp.size() == k){
                cnt += (n - r);
                mpp[nums[l]] -= 1;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l += 1;
            }
            r += 1;
        }
        return cnt;
    }
};