class Solution {
private:
    int findCnt(vector<int>& portions , long long success , int curSpell , int m){
        int low = 0 , high = m - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long curStrength = (long long) portions[mid] * curSpell;
            if(curStrength >= success) high = mid - 1;
            else low = mid + 1;
        }
        return (m - low);
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size() , m = potions.size();
        sort(potions.begin() , potions.end());
        vector<int>cntPairs;
        for(int i = 0 ; i < n ; i++){
            int cnt = findCnt(potions , success , spells[i] , m);
            cntPairs.push_back(cnt);
        }
        return cntPairs;
    }
};