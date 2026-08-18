class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> hashMap;
        int maxEl = 0;
        for(int it : nums){
            hashMap[it] += 1;
            maxEl = max(maxEl , it);
        }

        if(k == n) return maxEl;

        if(k == 1){
            maxEl = -1;
            for(auto it: hashMap){
                if(it.second == 1) maxEl = max(maxEl , it.first);
            }
            return maxEl;
        }

        int ans = -1;
        if(hashMap[nums[0]] == 1) ans = max(ans , nums[0]);
        if(hashMap[nums[n-1]] == 1) ans = max(ans , nums[n-1]);
        return ans;
    }
};