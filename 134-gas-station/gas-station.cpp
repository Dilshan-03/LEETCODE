class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = accumulate(gas.begin() , gas.end() , 0);
        int totalCost = accumulate(cost.begin() , cost.end() , 0);
        if(totalCost > totalGas) return -1;
        int total = 0;
        int start = 0;
        //Greedy strategy
        for(int i = 0 ; i < n ; i++){
            total += (gas[i] - cost[i]);
            if(total < 0){
                total = 0;
                start = i + 1;
            }
        }
        return start;
    }
};