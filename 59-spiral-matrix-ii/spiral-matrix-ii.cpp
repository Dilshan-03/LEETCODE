class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n , vector<int>(n));
        int top = 0 , down = n - 1;
        int left = 0 , right = n - 1;
        int val = 1;
        while(top <= down && left <= right){
            //Left to right
            for(int i = left ; i <= right ; i++) {
                matrix[top][i] = val;
                val += 1;
            }
            top += 1;
            //Top to bottom 
            for(int i = top ; i <= down ; i++){
                matrix[i][right] = val;
                val += 1;
            }
            right -= 1;
            //Right to Left
            if(top <= down){
                for(int i = right ; i >= left ; i--){
                    matrix[down][i] = val;
                    val += 1;
                }
                down -= 1;
            }
            //Bottom to top
            if(left <= right){
                for(int i = down ; i >= top ; i--){
                    matrix[i][left] = val;
                    val += 1;
                }
                left += 1;
            }
        }
        return matrix;
    }
};