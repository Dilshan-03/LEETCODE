class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for(string it : operations){
             if(it[1] == '+') val += 1;
             else val -= 1;
        }
        return val;
    }
};