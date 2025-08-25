class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<int> ans;
        int row = 0 , col = 0;
        bool left_to_right = true;
        while(row < n && col < m){
            if(left_to_right){
                while(true){
                    ans.push_back(mat[row][col]);
                    if(row  == 0){
                        if(col + 1 < m) col = col + 1;
                        else row = row + 1;
                        break;
                    }
                    else if(col + 1 == m){
                        row = row + 1;
                        break;
                    }
                    row--;
                    col++;
                }
                
            }
            else{
                while(true){
                    ans.push_back(mat[row][col]);
                    if(col == 0){
                        if(row + 1 < n) row = row + 1;
                        else col = col + 1;
                        break;
                    }
                    else if(row + 1 == n){
                        col = col + 1;
                        break;
                    }
                    row++;
                    col--;
                }
               
            }
            left_to_right = !(left_to_right);   
        }
        return ans;
    }
};