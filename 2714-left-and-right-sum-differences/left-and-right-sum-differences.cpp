class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum , result(n , 0);
        int curSum = 0;
        for(int i = 0 ; i < n ; i++){
            prefixSum.push_back(curSum);
            curSum += nums[i];
        }
        curSum = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            result[i] = abs(prefixSum[i] - curSum);
            curSum += nums[i];
        }
        return result;
    }
};