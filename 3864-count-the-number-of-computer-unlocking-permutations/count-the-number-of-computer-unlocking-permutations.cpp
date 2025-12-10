class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int mini = complexity[0];
        int mod = 1e9 + 7 ;
        long long  ans = 1;
        for(int i = 1 ; i < n ; i++){
            if(complexity[i] <= mini) return 0;
            ans = (ans * i) % mod ;
        }  
        return ans;
    }
};