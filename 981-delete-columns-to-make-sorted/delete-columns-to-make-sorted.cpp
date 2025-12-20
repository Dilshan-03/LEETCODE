class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].length();
        vector<int>col(len , 0);
        for(int i = 0 ; i < n - 1 ; i++){
            for(int k = 0 ; k < len ; k++){
                if(strs[i][k] > strs[i + 1][k]) col[k] = 1;
            }
        }
        return accumulate(col.begin() , col.end() , 0);
    }
};