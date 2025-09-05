class Solution {
private:
    void backTrack(int num , int n , int k , vector<int>& path , vector<vector<int>>& ans){
        if(path.size() == k){
            ans.push_back(path);
            return;
        }

        for(int i = num ; i <= n ; i++){
            path.push_back(i);
            backTrack(i + 1 , n , k , path , ans);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> combinations;
        backTrack(1 , n , k , path , combinations);
        return combinations;
    }
};