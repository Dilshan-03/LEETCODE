class Solution {
private:
    bool isPossible(vector<int>& nums , int maxDiff , int pairs , int n){
        int cntPairs = 0;
        int i = 0;
        while(i < n){
            //Greedy way , if the current adjacent pair  can have less than or equal maxDiff , then move don't take again that (i + 1)th index  
            if(i + 1 < n && nums[i + 1] - nums[i] <= maxDiff){
                cntPairs += 1;
                i += 1;
            }
            //Regardless of anything , i has to move by 1 step
            i += 1;
        }
        return (cntPairs >= pairs);
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        //Greedy way to get minimum difference
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int low = 0 , high = nums[n - 1] - nums[0];
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(nums , mid , p , n)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
        //TC : O(N log N) + O(N log (maxi - min))
        //SC : O(1)
    }
};