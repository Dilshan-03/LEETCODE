class Solution {
public:
    struct SmartWindow{
        int K;
        multiset<int> low , high;
        long long lowSum = 0;
        SmartWindow(int k) : K(k){};
        int windowSize(){
            return low.size() + high.size();
        }
        void reBalance(){
            int need = min(K , windowSize());
            //Remove the elements from low and push to high if low contains more than need
            while(low.size() > need){
                auto it = prev(low.end());
                int x = *it;
                low.erase(it);
                high.insert(x);
                lowSum -= x;
            }
            //Remove the elements from high and push to low if low contains less than need & high is not empty
            while(low.size() < need && !high.empty()){
                auto it = high.begin();
                int x = *it;
                high.erase(it);
                low.insert(x);
                lowSum += x;
            }
        }
        
        void add(int x){
            if(low.empty() || x <= *prev(low.end())){
                low.insert(x);
                lowSum += x;
            }
            else high.insert(x);
            reBalance();
        }
        void remove(int x){
            auto it = low.find(x);
            if(it != low.end()){
                low.erase(it);
                lowSum -= x;
            }
            else{
                it = high.find(x);
                if(it != high.end()) high.erase(it);
            }
            reBalance();
        }

        long long query(){
            return lowSum;
        }
    };
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        k -= 1;
        long long ans = 0;
        SmartWindow window(k);
        for(int i = 1 ; i <= dist + 1 ; i++){
            window.add(nums[i]);
        }
        ans = window.query();
        for(int i = 2 ; i + dist < n ; i++){
            window.remove(nums[i - 1]);
            window.add(nums[i + dist]);
            ans = min(ans , window.query());
        }
        return nums[0] + ans;
    }
};