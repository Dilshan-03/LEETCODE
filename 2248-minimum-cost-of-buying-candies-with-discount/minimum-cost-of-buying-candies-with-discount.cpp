class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin() , cost.end());
        int n = cost.size();
        int c = 0 , flag = 2;
        for(int i = n - 1 ; i >= 0 ; i--){
            if(flag == 0){
                flag = 2;
                continue;
            }
            c += cost[i];
            flag -= 1;
        }
        return c;
    }
};