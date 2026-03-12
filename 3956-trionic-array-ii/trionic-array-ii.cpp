class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long result = LONG_MIN ;
        long long preSum = nums[0];
        int l = 0 , p = 0 , q = 0;
        for(int r = 1 ; r < n ; r++){
            preSum += nums[r];
            //If strictly increasing or decreasing is not possible , then shrink the window
            if(nums[r - 1] == nums[r]){
                l = r;
                preSum = nums[r];
            }
            //Check for assinging p
            else if(nums[r - 1] > nums[r]){
                if(r > 1 && nums[r - 2] < nums[r - 1]){
                    p = r - 1;
                    //Update the l value , because l->p->q->r has to be valid . l->q->p->r is not valid
                    while(l < q){
                      preSum -= nums[l];
                      l += 1;
                    }
                    //Reduce the negative numbers in the [l..p] to get maximum suml
                    while(l < p - 1 && nums[l] < 0){
                       preSum -= nums[l];
                       l += 1;
                    } 
                }
            }
            //Marking q and if valid window , then check for maximum Sum
            else{
                //nums[r-1] < nums[r]
                if(r > 1 && nums[r - 1] < nums[r - 2]) q = r - 1;
                //If we have valid window , then just look for maxsum
                if(l < p && p < q) result = max(result , preSum);
                
            }
        }
        return result;
    }
};