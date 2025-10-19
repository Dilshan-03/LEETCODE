class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin() , happiness.end());
        int n = happiness.size();
        long long maxHappiness = 0;
        int i = n - 1;
        while(i >= 0 && k > 0 && happiness[i] >= (n - 1 - i)){
            maxHappiness += (happiness[i] - (n - 1 - i));
            k -= 1;
            i -= 1;
        }
        return maxHappiness;
    }
};