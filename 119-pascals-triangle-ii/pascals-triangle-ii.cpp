class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        vector<int> res;
        res.push_back(1);
        for(int i = 0 ; i < rowIndex ; i++){
            ans = ans * (rowIndex - i);
            ans = ans / (i + 1);
            res.push_back(ans);
        }
        return res;
    }
};