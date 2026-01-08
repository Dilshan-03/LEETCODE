class Solution {
private:
    int f(int i , int j , vector<int>& nums1, vector<int>& nums2 , vector<vector<int>>& dp ){
        if(i == 0 || j == 0 ) return -1e9;
        if(dp[i][j] != -1) return dp[i][j];
        int take = (nums1[i - 1] * nums2[j - 1]) + max(0 , f(i - 1 , j - 1 , nums1 , nums2 , dp));
        int skip1 = f(i - 1 , j , nums1 , nums2 , dp);
        int skip2 = f(i , j - 1 , nums1 , nums2 , dp);
        return dp[i][j] = max({take , skip1 , skip2});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m  = nums2.size();
        vector<int> prev(m + 1 , -1e9);
        //return f( n  , m  , nums1 , nums2 , dp);
        for(int i = 1 ; i <= n ; i++){
            vector<int> cur(m + 1 , -1e9);
            for(int j = 1 ; j <= m ; j++){
                int take = (nums1[i - 1] * nums2[j - 1]) + max(0 , prev[j - 1]);
                int skip1 = prev[j];
                int skip2 = cur[j - 1];
                cur[j] = max({take , skip1 , skip2});
            }
            prev = cur;
        }
        return prev[m];
    }
};