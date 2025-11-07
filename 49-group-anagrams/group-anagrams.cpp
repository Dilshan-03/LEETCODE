class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<int>> hashMap;//{ sorted string , {indices}}
        int n = strs.size();
        for(int i = 0 ; i < n ; i++){
            string temp = strs[i];
            //To reduce complexity , since string contains only lowercase letters , we can use counting sort approach too
            sort(temp.begin() , temp.end());
            hashMap[temp].push_back(i); //store the anagrams with indices
        }

        vector<vector<string>> result;
        for(auto it : hashMap){
            vector<string> anagrams;
            for(int i : it.second){
                anagrams.push_back(strs[i]);
            }
            result.push_back(anagrams);
        }
        return result;

        //TC : O(N * M log M) + O(N) -> N (number of string in strs) , M (avg length of each string)
        //SC : O(N + N) + O(N)(result)
    }
};