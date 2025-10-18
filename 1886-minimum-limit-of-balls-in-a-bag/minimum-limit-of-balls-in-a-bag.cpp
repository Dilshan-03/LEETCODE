class Solution {
private:
    bool isPossible(vector<int>& nums , int maxOperations , int limit){
        int operations = 0;
        //To calculate no of operations to maintain limit as max no of balls: we have to find no of bags needed to have limit as maximum no of balls for each element in the array
        //Then (no of bags - 1) would be the no of operations for each element
        for(int i = 0 ; i < nums.size() ; i++){
           int bags = ceil((double) nums[i] / limit);
           operations += bags - 1;
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