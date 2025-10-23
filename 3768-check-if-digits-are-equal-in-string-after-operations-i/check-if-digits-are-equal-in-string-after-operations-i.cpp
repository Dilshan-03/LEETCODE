class Solution {
public:
    bool hasSameDigits(string s) {
        while(true){
            int n=s.length();
            string temp="";
            for(int i=0;i<n-1;i++){
                int sum=0;
                int digit1= s[i] - '0';
                int digit2= s[i + 1] - '0';
                sum =( digit1 + digit2 ) % 10;
                temp+=sum;
            }
            if(temp.length() == 2) return temp[0] == temp[1];
            if(temp.length() < 2) return false;
            s= temp;
        }
    }
};