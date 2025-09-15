class Solution {
public:
    int maxDistance(vector<int>& colors) {

        int n = colors.size();
        int ans = 0;
        for(int i = 1 ; i < n ; i++){
            if(colors[0] != colors[i]) ans = max(ans , i);
            if(colors[n - 1] != colors[i]) ans = max(ans , n - 1 - i);
        }
        return ans;
    }
};