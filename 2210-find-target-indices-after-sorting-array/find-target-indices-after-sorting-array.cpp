class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
     vector<int> targetIndicesArr;
     sort(nums.begin() , nums.end());   
     for(int i = 0 ; i < nums.size() ; i++){
        if(nums[i] == target) targetIndicesArr.push_back(i);
        else if(nums[i] > target) break;
     }
     return targetIndicesArr;
    }
};