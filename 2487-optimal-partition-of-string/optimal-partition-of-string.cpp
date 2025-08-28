class Solution {
public:
    int partitionString(string s) {
        vector<int> lastSeen(26 , -1);
        int n = s.length();
        int partitionCnt = 1;
        int currentSubstrStart = 0;
        for(int i = 0 ; i < n ; i++){
            //Check whether the current char already appears within the current window , if so put a partition and change the partition start
            //If the current character already appears but it's outside the current window , don't care about it , it's handled by the condition
            if(lastSeen[s[i] - 'a'] >= currentSubstrStart){
                partitionCnt += 1;
                currentSubstrStart = i;   
            }
            lastSeen[s[i] - 'a'] = i;
        }
        return partitionCnt;
    }
};