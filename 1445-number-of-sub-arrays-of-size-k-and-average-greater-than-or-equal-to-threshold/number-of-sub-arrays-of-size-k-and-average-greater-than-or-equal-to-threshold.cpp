class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0 , cnt = 0;
        int l = 0 , r = 0;
        while(r < n){
            sum += arr[r];
            //Whenever , window size is greater than k , shrink the window
            if(r - l + 1 > k ){
                sum -= arr[l];
                l += 1;
            }
            //If window is of size k and average >= threshold , then cnt it
            if(r - l + 1 == k && sum / k >= threshold) cnt += 1;
            r += 1;
        }
        return cnt;
    }
};