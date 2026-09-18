class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> minElements(n);
        int mini = INT_MAX;
        for(int i = n - 1 ; i >= 0 ; i--){
            mini = min(mini , nums[i]);
            minElements[i] = mini;
        }

        int maxi = nums[0];
        int min_score = INT_MAX;
        for(int i = 0 ; i < n ; i++){
            maxi = max(maxi , nums[i]);
            min_score = min(min_score , maxi - minElements[i]);
            if(min_score <= k) return i;
        }
        return -1;
    }
};