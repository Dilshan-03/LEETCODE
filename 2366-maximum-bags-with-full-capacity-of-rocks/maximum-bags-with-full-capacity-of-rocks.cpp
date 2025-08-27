class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> needToFill;
        for(int i = 0 ; i < n ; i++){
            needToFill.push_back(capacity[i] - rocks[i]);;
        }

        sort(needToFill.begin() , needToFill.end());
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            if(needToFill[i] == 0) cnt += 1;
            else if(needToFill[i] <= additionalRocks){
                additionalRocks -= needToFill[i];
                cnt += 1;
            }
            else break;
        }
        return cnt;
    }
};