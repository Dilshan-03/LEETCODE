class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int n = arr.size();
        //Finding out the minimum Absolute Difference
        int mini = 1e9;
        for(int i = 1 ; i < n ; i++){
            mini = min(mini , abs(arr[i] - arr[i - 1]));
        }
        //Store all the pairs which have minimum absolute difference
        vector<vector<int>> ans;
        for(int i = 1 ; i < n ; i++){
            if(abs(arr[i] - arr[i - 1]) == mini){
                ans.push_back({arr[i - 1] , arr[i]});
            }
        }
        return ans;
    }
};