class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int , int> hashMap;
        for(int it : nums){
            if(hashMap[it] != 0) return true;
            hashMap[it]++;
        }
        return false;
    }
};