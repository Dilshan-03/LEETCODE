class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin() , citations.end());
        int n = citations.size();
        int low = 0 , high = n - 1;
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int val = citations[mid];
            if(val >= (n - mid)){
                ans =   n - mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};