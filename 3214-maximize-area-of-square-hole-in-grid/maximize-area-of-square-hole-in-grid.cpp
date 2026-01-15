class Solution {
private:
    int longestConsecutiveBars(vector<int>& bars){
        int n = bars.size();
        int longest = 1 , cur = 1;

        for(int i = 1 ; i < n ; i++){
            if(bars[i]  == bars[i - 1] + 1 ) cur += 1;
            else cur = 1;
            longest = max(longest , cur);
        }
        return longest;
    }
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());
        //Find the longest consecutive Horizontal and Vertical Bars that can be removed
        int hLongest = longestConsecutiveBars(hBars);
        int lLongest = longestConsecutiveBars(vBars);
        //Greedy , Longest consecutive always give the ares to be maximum
        //Minimum is to convert even rectangles  to maximal squares
        int sideLen = min(hLongest , lLongest) + 1;
        return sideLen * sideLen;
    }
};