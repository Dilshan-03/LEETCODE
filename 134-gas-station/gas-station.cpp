class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = accumulate(gas.begin() , gas.end() , 0);
        int totalCost = accumulate(cost.begin() , cost.end() , 0);
        //Edge case -> if total gas that can be accumulated is less than cost for travelling , then definitely , it's not possible
        if(totalCost > totalGas) return -1;
        int total = 0;
        int start = 0;
        //Greedy strategy
        for(int i = 0 ; i < n ; i++){
            total += (gas[i] - cost[i]);
            //If the current sum is negative , then surely . points from start to current index(i) will not be starting index --> Greedy strategy
            if(total < 0){
                total = 0;
                start = i + 1;//Reason for not exploring all stations from start , question guarantees that unique solution is always present
            }
        }
        return start;
    }
};