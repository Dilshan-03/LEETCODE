class Solution {
private:
    bool isPossible(vector<int>& candies , long long k , int maxCandy , int n){
        long long childCnt = 0;
        for(int i = 0 ; i < n ; i++){
            //Counting , how many children can have current piles of candies
            childCnt += (candies[i] / maxCandy);
        }
        return (childCnt >= k);
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n = candies.size();
        //technically low has to point to 0 , since 0 is also a answer . but shrinking down of answer space make sure that , high points to 0 , if it's the answer
        int low = 1 , high = *max_element(candies.begin() , candies.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(isPossible(candies , k , mid , n)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
        //TC : O(N log (max_element))
        //SC : O(1)
    }
};