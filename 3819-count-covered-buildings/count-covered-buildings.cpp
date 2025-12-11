class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> rowMax(n + 1 , 0) , rowMin(n + 1 , n + 1);
        vector<int> colMax(n + 1 , 0) , colMin(n + 1 , n + 1);
        //Mark the extremes and check for validity
        for(auto it : buildings){
            int x = it[0];
            int y = it[1];
            //Let's say (i , j) , here j value is same for all same row elements and i value is same for all same column elements
            //Row max -> leftMost point , Row min -> RightMost point
            //Col Max -> BottomMost point , Col Min -> Topmost point
            rowMax[y] = max(rowMax[y] , x);
            rowMin[y] = min(rowMin[y] , x);
            colMax[x] = max(colMax[x] , y);
            colMin[x] = min(colMin[x] , y);
        }
        int cnt = 0;
        for(auto it : buildings){
            int x = it[0] , y = it[1];
            if((rowMin[y] < x && x < rowMax[y]) && (colMin[x] < y && y <  colMax[x])) cnt += 1;
        }
        return cnt;
    }
};