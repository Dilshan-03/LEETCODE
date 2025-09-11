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
        while(k && carry){
            int digit = k % 10;
            int sum = digit + carry;
            res.push_back(sum  % 10);
            k = k / 10;
            carry = sum / 10;
        }
        while(carry){
            res.push_back(carry % 10);
            carry = carry / 10;
        }
        while(k){
            res.push_back(k % 10);
            k = k / 10;
        }
        reverse(res.begin() , res.end());
        return res;
    }
};