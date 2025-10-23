class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int , int> mpp;
        vector<vector<int>> mergedArray;
        for(auto it : items1){
            mpp[it[0]] = it[1];
        }
        for(auto it : items2){
            mpp[it[0]] += it[1];
        }
        for(auto it : mpp){
            mergedArray.push_back({it.first , it.second});
        }
        return mergedArray;
    }
};