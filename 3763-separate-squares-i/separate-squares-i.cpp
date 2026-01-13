class Solution {
private:
    double calculateArea(vector<vector<int>>& squares , double line){
        double aAbove = 0, aBelow = 0;
        int n = squares.size();
        for(int i = 0; i < n; i++){
            int x = squares[i][0], y = squares[i][1];
            int l = squares[i][2];
            double total = (double) l * l;
            
            if(line <= y){
                aAbove += total;
            } 
            else if(line >= y + l){
                aBelow += total;
            } 
            else{
                 // The line intersects the square.
                double aboveHeight = (y + l) - line;
                double belowHeight = line - y;
                aAbove += l * aboveHeight;
                aBelow += l * belowHeight;
            }
        }
        return aAbove - aBelow;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9 , high = 0;
        int n = squares.size();
        for(int i = 0 ; i < n ; i++){
            low = min(low , (double)squares[i][1]);
            high = max(high , (double)(squares[i][1] + squares[i][2]));
        }
        //cout<<low << ' ' << high<<endl;
        double diff = 1e-5;
        while(high - low > diff ){
            double mid = (high + low) / 2.0 ;
            if(calculateArea(squares , mid) > 0) low = mid;
            else high = mid;
        }
        return high;
    }
};