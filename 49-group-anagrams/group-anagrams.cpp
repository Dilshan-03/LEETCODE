class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<string> temp(strs);
        for(int i = 0 ; i < n ; i++)
           sort(temp[i].begin() , temp[i].end());
        int i = 0 ;
        vector<vector<string>> result;
        vector<int> visited(n , 0);
        while(i < n){
            if(visited[i]){
                i += 1;
                continue;
            }
            visited[i] = 1;
            vector<string> curAnagram;
            curAnagram.push_back(strs[i]);
            for(int j = i + 1 ; j < n ; j++){
                if(temp[i] == temp[j]){
                    curAnagram.push_back(strs[j]);
                    visited[j] = 1;
                }
            }
            result.push_back(curAnagram);
            i += 1;
        }
        return result;
    }
};