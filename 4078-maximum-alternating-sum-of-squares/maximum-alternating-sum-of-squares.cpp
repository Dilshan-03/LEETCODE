class Solution {
private:
    static bool comp(int a , int b){
        return abs(a) < abs(b);
    }
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin() , nums.end(), comp);
        long long sum = 0;
        int l = 0 , r = nums.size() - 1;
        while(l < r){
            sum += (nums[r] * nums[r]);
            sum -= (nums[l] * nums[l]);
            l += 1;
            r -= 1;
        }
        if(l == r) sum += (nums[l] * nums[l]);
        return sum;
    }
};