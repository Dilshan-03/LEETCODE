class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.length();
        int i = 0 ;
        int timeReq = 0;
        while(i < n - 1){
            if(colors[i] == colors[i + 1]){
                char ch = colors[i];
                int totalTime = 0;
                int maxTime = 0;
                while(i < n && colors[i] == ch){
                    maxTime = max(maxTime , neededTime[i]);
                    totalTime += neededTime[i];
                    i += 1;
                }
                timeReq += (totalTime - maxTime);
            }
            else i += 1;   
        }
        return timeReq;
    }
};