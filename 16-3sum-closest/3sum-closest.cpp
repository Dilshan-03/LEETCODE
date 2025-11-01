class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 1e9;
        //Brute force solution
       /* for(int i = 0 ; i < n  ; i++){
            for(int j = i + 1 ; j < n ; j++){
                for(int k = j + 1 ; k < n ; k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == target) return target;
                    if(abs(sum - target) < abs(ans - target)) ans = sum;
                }
            }
        }
        return ans;*/

        sort(nums.begin() , nums.end());
        for(int i = 0 ; i < n ; i++){
            int l = i + 1 , r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) return sum;
                if(abs(sum - target) < abs(ans - target)) ans = sum;
                if(sum < target) l += 1;
                else r -= 1;
            }
        }
        return ans;
    }
};