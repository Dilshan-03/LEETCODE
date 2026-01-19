class Solution {
private:
    int getSum(vector<vector<int>>& preSum , int x1 , int y1 , int x2 , int y2){
        return preSum[x2][y2] - preSum[x1 - 1][y2] - preSum[x2][y1 - 1] + preSum[x1 - 1][y1 - 1];      
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
       int n = mat.size() , m = mat[0].size();
       vector<vector<int>> preSum(n + 1, vector<int>( m + 1, 0)); 
       for(int i = 1 ; i <= n ; i++){
           for(int j = 1 ; j <= m ; j++){
               preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + mat[i - 1][j - 1];
           }
       }
       
       int low = 1 , high = min(n , m) , ans = 0;
       while(low <= high){
           bool find = false;
           int mid = low + (high - low) / 2; 
           for(int i = 1 ; i <= n - mid + 1 ; i++){
               for(int j = 1 ; j <= m - mid + 1 ; j++){
                    int sum = getSum(preSum , i , j , i + mid - 1 , j + mid - 1);
                    if(sum <= threshold){
                        find = true;
                    }
               }
           }
           if(find) low = mid + 1;
           else high = mid - 1;
       }
       return high;
    }
};