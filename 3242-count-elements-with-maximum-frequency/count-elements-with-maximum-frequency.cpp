class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int , int> freqMap;
        int maxFreq = 0;
        for(auto it : nums){
            freqMap[it]++;
            maxFreq = max(maxFreq , freqMap[it]);
        }
        int cnt = 0;
        for(auto it : freqMap){
            if(it.second == maxFreq) cnt += it.second;
        }
        return cnt;
    }
};