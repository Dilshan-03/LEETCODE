class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.length() , m = b.length();
        int i = n - 1 , j = m - 1;
        int carry = 0;
        string result = "";
        while(i >= 0 && j >= 0){
            int sum = (a[i] - '0') + (b[j] - '0') + carry;
            if(sum == 0) result.push_back('0');
            else if(sum == 1){
                result.push_back('1');
                carry = 0;
            }
            else{
                if(sum == 2) result.push_back('0');
                else result.push_back('1'); // sum == 2
                carry = 1;
            }
            i -= 1;
            j -= 1;
        }
        while(i >= 0){
            int sum = (a[i] - '0') + carry;
            if(sum == 0) result.push_back('0');
            else if(sum == 1){
                result.push_back('1');
                carry = 0;
            }
            //sum == 2
            else{
                result.push_back('0');
                carry = 1;
            }
            i -= 1;
        }

        while(j >= 0){
            int sum = (b[j] - '0') + carry;
            if(sum == 0) result.push_back('0');
            else if(sum == 1){
                result.push_back('1');
                carry = 0;
            }
            //sum == 2
            else{
                result.push_back('0');
                carry = 1;
            }
            j -= 1;
        }

        if(carry) result.push_back('1');
        reverse(result.begin() , result.end());
        return result;
    }
};