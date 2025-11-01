class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 1e9;
        for(int i = 0 ; i < n  ; i++){
            for(int j = i + 1 ; j < n ; j++){
                for(int k = j + 1 ; k < n ; k++){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == target) return target;
                    if(abs(sum - target) < abs(ans - target)) ans = sum;
                    /*if(sum > target){
                        if(sum - target < abs(ans - target)){
                            ans = sum;
                        }
                    }
                    else{
                        if(target - sum < abs(ans - target) ){
                            ans = sum;
                        }
                    }*/
                }
            }
        }
        return ans;
    }
};