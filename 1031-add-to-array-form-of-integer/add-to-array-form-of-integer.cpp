class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> res;
        int carry = 0;
        //Simulation of Normal arithmetic addition
        for(int i = n - 1 ; i >= 0 ; i--){
            int digit = k % 10;
            k = k / 10;
            int sum = num[i] + digit + carry;
            res.push_back(sum % 10);
            carry =  sum / 10;
        }
        //If either given array ran out , but either of k or carry remains , do the same as above , by just ignoring num[i]
        k = k + carry;
        while(k){
            int sum = k % 10;
            res.push_back(sum);
            k = k / 10;
        }
        //Since res stores answer in reverse order , reverse it up
        reverse(res.begin() , res.end());
        return res;
    }
};