class Solution {
private:
    int gcd(int a ,  int b){
        if(b == 0) return a;
        return gcd(b , a % b);
    }
public:
    int gcdOfOddEvenSums(int n) {
        //Sum of first N odd numbers -> n * n
        int oddSum = n * n ;
        //Sum of first N even number -> n * (n + 1)
        int evenSum = n * (n + 1);
        return gcd(oddSum , evenSum);
    }
};