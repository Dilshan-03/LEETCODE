class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size() , m = mat[0].size();
        vector<int> ans;
        int row = 0 , col = 0;
        bool left_to_right = true;
        while(row < n && col < m){
            if(left_to_right){
                // 2 cases for out of boundary while going from left to right 
                while(true){
                    ans.push_back(mat[row][col]);
                     // If right element is there , then just jump to it or else move to next row and break
                    if(row  == 0){
                        if(col + 1 < m) col = col + 1;
                        else row = row + 1;
                        break;
                    }
                     // If ur in last col , then anyway we have to move to next row and break
                    else if(col + 1 == m){
                        row = row + 1;
                        break;
                    }
                    //Just the move the pointers accordingly for left to right direction movement
                    row--;
                    col++;
                }
                
            }
            else{
                while(true){
                    ans.push_back(mat[row][col]);
                    // If  element is there at the down  , then just jump to it or else move to next col and break
                    if(col == 0){
                        if(row + 1 < n) row = row + 1;
                        else col = col + 1;
                        break;
                    }
                    // If ur in last row , then anyway we have to move to next col and break
                    else if(row + 1 == n){
                        col = col + 1;
                        break;
                    }
                    //Just the move the pointers accordingly for right to left direction movement
                    row++;
                    col--;
                }
               
            }
            //Just flip the flag everytime
            left_to_right = !(left_to_right);   
        }
        return ans;
    }
};