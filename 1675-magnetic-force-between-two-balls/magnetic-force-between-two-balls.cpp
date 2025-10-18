class Solution {
private:
    bool isPossible(vector<int>& position , int maxNeed , int limit){
        int last = position[0] , balls = 1;
        for(int i = 1 ; i < position.size() ; i++){
            if(position[i] - last >= limit){
                last = position[i];
                balls += 1;
            }
        }
        return (balls >= maxNeed);
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin() , position.end());
        int n = position.size();
        int low = 0 , high = position[n - 1] - position[0];
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(position , m , mid)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};