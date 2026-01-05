class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int mini = INT_MAX;
        int cntNeg = 0;
        long long sum = 0;
        //Count the number of negatives and find the minimum absolute element
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] < 0) cntNeg += 1;
                sum += abs(matrix[i][j]);
                mini = min(mini , abs(matrix[i][j]));
            }
        }
        //If even number of elements are there , then by all operations we can convert everything to positive
        if(cntNeg % 2 == 0) return sum; 
        //IF odd number of elements are there , then just remove the element which has minimum magnitude
        return sum - 2 * mini;
    }
};