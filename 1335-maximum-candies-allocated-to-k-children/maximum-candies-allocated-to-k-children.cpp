class Solution {
private:
    bool isPossible(vector<int>& candies , long long k , int maxCandy , int n){
        if(!maxCandy) return true;
        long long childCnt = 0;
        for(int i = 0 ; i < n ; i++){
            childCnt += (candies[i] / maxCandy);
        }
        return (childCnt >= k);
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        int low = 0 , high = *max_element(candies.begin() , candies.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(candies , k , mid , n)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};