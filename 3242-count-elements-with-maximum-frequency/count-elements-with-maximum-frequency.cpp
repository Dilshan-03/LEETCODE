class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int , int> freqMap;
        int maxFreq = 0;
        int totalFreq = 0;
        //Similar to that of finding second largest element approach
        for(auto it : nums){
            freqMap[it]++;
            int curFreq = freqMap[it];
            if(curFreq > maxFreq){
                maxFreq = curFreq;
                totalFreq = curFreq;
            }
            else if(curFreq == maxFreq) totalFreq += curFreq;
        }
        
        return totalFreq;
    }
};