class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> hash(26 , 0);
        int n = s.length();
        //
        for(int i = 0 ; i < n; i++){
            hash[s[i] - 'a'] = i;
        }
        
        int maxLimit = -1;
        int start = 0;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            maxLimit = max(maxLimit , hash[s[i] - 'a']);
            if(maxLimit == i){
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};