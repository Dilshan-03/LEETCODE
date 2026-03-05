class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int option1 = 0 , option2 = 0;
        for(int i = 0 ; i < n ; i++){
            char expected1 = i % 2 == 0 ? '0' : '1';
            char expected2 = i % 2 == 0 ? '1' : '0';
            if(s[i] != expected1) option1 += 1;
            if(s[i] != expected2) option2 += 1;
        }
        return min(option1 , option2);
    }
};