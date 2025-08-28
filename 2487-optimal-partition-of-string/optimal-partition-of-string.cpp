class Solution {
public:
    int partitionString(string s) {
        vector<int> hash(26 , 0);
        int n = s.length();
        int partitionCnt = 1;
        for(int i = 0 ; i < n ; i++){
            if(hash[s[i] - 'a'] != 0){
                partitionCnt += 1;
                for(int i = 0 ; i < 26 ; i++) hash[i] = 0;   
            }
            hash[s[i] - 'a'] = 1;
        }
        return partitionCnt;
    }
};