class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int area = 0 , maxi = 0;
        for(int i = 0 ; i < n ; i++){
            int curLen = dimensions[i][0];
            int curWidth = dimensions[i][1];
            //Finding out the hyptonese and comparing with maximum value everytime, just ignoring the sqrt part for simplicity
            int diagonal = curLen * curLen + curWidth * curWidth;
            if(diagonal > maxi){
                maxi = diagonal;
                area = curLen * curWidth;
            }
            else if(diagonal == maxi) area = max(area ,curLen * curWidth);
        }
        return area;
    }
};