class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int sum = 0;
        //Just grp the closer elements together , just a greedy way for maximising the answer
        for(int i = 0 ; i < n; i += 2){
            sum += nums[i];
        }
        return sum;
    }
};