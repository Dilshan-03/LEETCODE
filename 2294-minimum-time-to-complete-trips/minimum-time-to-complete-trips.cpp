class Solution {
private:
    bool isPossible(vector<int>& time , int totalTrips , long long t , int n){
        int trips = 0;
        for(int i = 0 ; i < n ; i++){
            trips += (t /(long long)time[i]);
            if(trips >= totalTrips) break;
        }
        return (trips >= totalTrips);
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int mini = *min_element(time.begin() , time.end());
        long long low = 1 , high = 1LL * mini * totalTrips;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(isPossible(time , totalTrips , mid , n)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};