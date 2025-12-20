class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int len = strs[0].length();
        int cnt = 0;
        for(int i = 0 ; i < len ; i++){
            for(int k = 0 ; k < n - 1 ; k++){
                if(strs[k][i] > strs[k + 1][i]){
                    cnt += 1;
                    break;
                }
            }
        }
        return cnt;
    }
};