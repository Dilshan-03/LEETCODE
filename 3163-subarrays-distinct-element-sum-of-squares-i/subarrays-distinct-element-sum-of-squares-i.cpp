class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size() , ans = 0;    
        for(int i = 0 ; i < n ; i++){
            unordered_map<int , int> hashMap;
            for(int j = i ; j < n ; j++){
                hashMap[nums[j]] += 1;
                ans += (hashMap.size() * hashMap.size());
            }
        }
        return ans;
    }
};