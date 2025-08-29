class Solution {
private:
    int encrypt(int n){
        int cnt = 0;
        int digit = 0;
        while(n > 0){
            digit = max(digit , n % 10);
            n = n / 10;
            cnt += 1;
        }

        int curNum = 0;
        for(int i = 0 ; i < cnt ; i++) curNum = curNum * 10 + digit;
        return curNum;
    }
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums) sum += encrypt(it);
        return sum;
    }
};