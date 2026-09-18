class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count_negative = 0;
        for(auto no : nums){
            if(no == 0) return 0;
            else if(no < 0) count_negative += 1;
        }
        if(count_negative % 2 == 1) return -1;
        return 1;
    }
};