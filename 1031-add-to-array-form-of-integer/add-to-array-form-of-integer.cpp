class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> res;
        int carry = 0;
        for(int i = n - 1 ; i >= 0 ; i--){
            int digit = k % 10;
            k = k / 10;
            int sum = num[i] + digit + carry;
            res.push_back(sum % 10);
            carry =  sum / 10;
        }
        k = k + carry;
        while(k){
            int sum = k % 10;
            res.push_back(sum);
            k = k / 10;
        }
        reverse(res.begin() , res.end());
        return res;
    }
};