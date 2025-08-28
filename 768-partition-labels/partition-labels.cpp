class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26 , 0);
        vector<int> ans;
        int n = s.length();
        //Store the last occurance of the character
        for(int i = 0 ; i < n; i++){
            last[s[i] - 'a'] = i;
        }
        
        int maxLimit = -1;
        int start = 0;
      
        //Greedy approach
        for(int i = 0 ; i < n ; i++){
            //Similar to jump game , find the maxLimit you can reach 
            maxLimit = max(maxLimit , last[s[i] - 'a']);
            //If the maxLimit is equal to current index , then it means that you can partition that half and find the ans
            if(maxLimit == i){
                ans.push_back(i - start + 1);
                start = i + 1;
            }
        }

        return ans;
    }
};