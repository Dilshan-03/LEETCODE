class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        int mod = (int)1e9 + 7;
        unordered_map<int , int> prevMap , nextMap;
        for(int i = 0 ; i < n ; i++) nextMap[nums[i]] += 1;
        for(int i = 0 ; i < n; i++){
            int prevCnt = prevMap[nums[i] * 2];
            //Update the nextMap to eliminate the frequency of current element on the right side
            nextMap[nums[i]] -= 1;
            int nextCnt = nextMap[nums[i] * 2];
            cnt = (cnt + ((prevCnt * 1LL * nextCnt) % mod)) % mod;
            //Update the frequency of current element of left side
            prevMap[nums[i]] += 1;
        }
        return cnt;
    }
};