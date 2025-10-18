class Solution {
private:
    bool isPossible(vector<int>& nums , int maxDiff , int pairs , int n){
        int cntPairs = 0;
        int i = 0;
        while(i < n){
            if(i + 1 < n && nums[i + 1] - nums[i] <= maxDiff){
                cntPairs += 1;
                i += 1;
            }
            i += 1;
        }
        return (cntPairs >= pairs);
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
      
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int low = 0 , high = nums[n - 1] - nums[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(nums , mid , p , n)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};