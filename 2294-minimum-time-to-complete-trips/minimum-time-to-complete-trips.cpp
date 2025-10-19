class Solution {
private:
    bool isPossible(vector<int>& time , int totalTrips , long long t , int n){
        int trips = 0;
        for(int i = 0 ; i < n ; i++){
            trips += (t / time[i]);
            if(trips >= totalTrips) return true;;
        }
        return false;
    }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int n = time.size();
        int mini = *min_element(time.begin() , time.end());
        //Max-Range : Bus with minimum time alone completes total no of trips
        long long low = 1 , high = 1LL * mini * totalTrips;
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(isPossible(time , totalTrips , mid , n)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};