class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        //Iterate through the array
        for(int i = 0 ; i < n ; i++){
            int val = sqrt(nums[i]);
            int fact = 0;
            int sum = 0;
            //Find the factors in O(sqrt(N)) time
            for(int j = 1 ; j <= val ; j++){
                if(nums[i] % j == 0){
                    fact += 1;
                    sum += j;
                    if(nums[i] / j != j){
                        sum += (nums[i] / j);
                        fact += 1;
                    }
                }
            }
            if(fact == 4) total += sum;
        }
        //TC: O(N*sqrt(M))
        //SC: O(1)
        return total;
    }
};