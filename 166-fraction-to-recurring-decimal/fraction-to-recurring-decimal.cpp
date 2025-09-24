class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string result = "";
        bool neg = false;
        if((long long) numerator * denominator < 0) neg = true;
        if(neg) result += "-";
        long long n = abs((long long) numerator);
        long long d = abs((long long) denominator);
        result += to_string(n / d);
        long long rem = n % d;
        if(rem == 0) return result;
        result += ".";
        unordered_map<long long , int> seen;
        while(rem != 0){
            if(seen.find(rem) != seen.end()){
                result.insert(seen[rem] , "(");
                result += ")";
                break;
            }

            seen[rem] = result.size();
            rem = rem * 10;
            result += to_string(rem / d);
            rem = rem % d;
        }

        return result;
    }
};