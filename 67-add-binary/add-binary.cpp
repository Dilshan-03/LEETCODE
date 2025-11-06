class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length() , m = b.length();
        int i = n - 1 , j = m - 1;
        int carry = 0;
        string result = "";
        while(i >= 0 || j >= 0){
            int sum = 0;
            if(i >= 0){
                sum += (a[i] - '0');
                i -= 1;
            }
            if(j >= 0){
                sum += (b[j] - '0');
                j -= 1;
            }
            sum += carry;
            //at max sum can take value as 3 , update the sum and carry field accordingly
            result.push_back(sum % 2 + '0');
            carry = sum / 2;
        }
        if(carry) result.push_back('1');
        reverse(result.begin() , result.end());
        return result;
    }
};