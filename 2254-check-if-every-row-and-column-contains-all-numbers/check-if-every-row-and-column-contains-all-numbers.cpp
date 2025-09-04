class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        //Checking for row
        for(int i = 0 ; i < n ; i++){
            vector<int> row(n + 1, 0);
            for(int j = 0 ; j < n ; j++){
                int num = matrix[i][j];
                if(num == 0 || num > n || row[num]) return false;
                row[num] =  true;
            }
        }

        // Checking for column
        for(int j = 0 ; j < n ; j++){
            vector<int> col(n + 1, 0);
            for(int i = 0 ; i < n ; i++){
                int num = matrix[i][j];
                if(num == 0 || num > n || col[num]) return false;
                col[num] =  true;
            }
        }
        return true;
    }
};