class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int , int> hashMap;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(hashMap[nums[i]]) return nums[i];
            hashMap[nums[i]] += 1;   
        }
        return 0;
    }
};