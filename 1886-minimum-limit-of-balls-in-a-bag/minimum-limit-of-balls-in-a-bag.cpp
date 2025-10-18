class Solution {
private:
    bool isPossible(vector<int>& nums , int maxOperations , int limit){
        int operations = 0;
        for(int i = 0 ; i < nums.size() ; i++){
           operations += ceil((double)nums[i] / limit) - 1;
           if(operations > maxOperations) return false;
        }
        return (operations <= maxOperations);
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxi = *max_element(nums.begin() , nums.end());
        int low = 1 , high = maxi;
        while(low <= high){
            int mid = (high + low) / 2;
            if(isPossible(nums , maxOperations , mid)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};