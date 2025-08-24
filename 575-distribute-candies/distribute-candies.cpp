class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        sort(candyType.begin() , candyType.end());
        int n = candyType.size();
        int cnt = 1;
        for(int i = 1 ; i < n ; i++){
            if(candyType[i] != candyType[i - 1]) cnt += 1;
        }

        if(cnt >= n / 2) return n / 2;
        return cnt;
    }
};