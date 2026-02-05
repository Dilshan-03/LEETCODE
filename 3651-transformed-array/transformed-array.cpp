class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 0){
                result.push_back(nums[(i + nums[i]) % n]);
            }
            else if(nums[i] < 0){
                int leftPos = abs(nums[i]) % n;
                result.push_back(nums[(i - leftPos + n) % n]);
            }
            else result.push_back(nums[i]);
        }
        return result;
    }
};