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
        if(hashMap[nums[0]] == 1 && hashMap[nums[n - 1]] == 1 ) return max(nums[0],nums[n-1]);
        else if(hashMap[nums[0]] == 1) return nums[0];
        else if(hashMap[nums[n-1]] == 1) return nums[n-1];
        return -1;
    }
};