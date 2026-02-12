class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length() , maxLen = 0;
        for(int i = 0 ; i < n ; i++){
            vector<int>hashMap(26 , 0);
            for(int j = i ; j < n ; j++){
                hashMap[s[j] - 'a'] += 1;
                int len = hashMap[s[j] - 'a'];
                bool flag = true;
                for(int k = 0 ; k < 26 ; k++){
                    if(hashMap[k] > 0)
                    {
                        if(hashMap[k] !=len) flag = false;
                    }
                }
                if(flag) maxLen = max(maxLen , j - i + 1);
            }
        }
        return maxLen;
    }
};