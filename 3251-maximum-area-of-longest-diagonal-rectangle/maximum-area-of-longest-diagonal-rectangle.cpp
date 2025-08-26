class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int area = 0 , maxDiagonal = 0;
        for(int i = 0 ; i < n ; i++){
            int curLen = dimensions[i][0];
            int curWidth = dimensions[i][1];
            //Finding out the hyptonese and comparing with maximum value everytime, just ignoring the sqrt part for simplicity
            int diagonal = (curLen * curLen) + (curWidth * curWidth);
            //If there is a larger diagonal available , then calculate the area of that diagonal
            if(diagonal > maxDiagonal){
                maxDiagonal = diagonal;
                area = curLen * curWidth;
            }
            //If there is anyother diagonal having same length as maxDiagonal then , update the area with maximum
            else if(diagonal == maxDiagonal) area = max(area ,curLen * curWidth);
        }
        return area;
    }
};