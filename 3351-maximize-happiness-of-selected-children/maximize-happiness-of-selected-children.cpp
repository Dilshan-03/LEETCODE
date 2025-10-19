class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        //Greedy approach , go for maxi happiness , every time
        sort(happiness.begin() , happiness.end());
        int n = happiness.size();
        long long maxHappiness = 0;
        int i = n - 1;
        //Since k <= n , don't have to check for i >= 0
        while(k > 0){
            maxHappiness += max(happiness[i] - (n - 1 - i) , 0);
            k -= 1;
            i -= 1;
        }
        return maxHappiness;
        //TC : O(N log N)
        //SC : O(1)
    }
};