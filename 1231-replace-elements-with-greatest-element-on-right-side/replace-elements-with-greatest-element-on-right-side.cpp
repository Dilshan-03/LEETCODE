class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        int maxi = -1;
        for(int i = n - 1 ; i >= 0 ; i--){
            res[i] = maxi;
            maxi = max(maxi , arr[i]);
        }
        return res;
    }
};