class Solution {
private:
    bool isPossibleSum(vector<int>& nums , int maxVal , int n){
        int l = 0 , r = n - 1;
        while(l < r){
            if(nums[l] + nums[r] > maxVal) return false;
            l += 1;
            r -= 1;
        }
        return true;
    }
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int low = 1 , high = (nums[n - 1] + nums[n - 2]);
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossibleSum(nums , mid , n)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};