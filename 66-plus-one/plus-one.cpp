class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        //Simulation for usual addition of 2 numbers in math
        vector<int> res;
        for(int i = n - 1 ; i >= 0 ; i--){
            int sum = digits[i] + carry;
            res.push_back(sum % 10);
            if(sum < 10) carry = 0;
        }
        if(carry) res.push_back(1);
        reverse(res.begin() , res.end());
        return res;
    }
};