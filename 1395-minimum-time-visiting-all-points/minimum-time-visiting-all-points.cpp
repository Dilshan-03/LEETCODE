class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;
        for(int i = 0 ; i < n - 1 ; i++){
            int hDist = abs(points[i][0] - points[i + 1][0]);
            int vDist = abs(points[i][1] - points[i + 1][1]);
            //Time for moving diagonally if possible
            time += min(hDist , vDist);
            //Time for moving either horizontal or vertical if possible
            time += abs(hDist - vDist);
        }
        return time;
    }
};