class Solution {
private:
    int f(int i , int j , vector<int>& nums1, vector<int>& nums2 , vector<vector<int>>& dp ){
        if(i == 0 || j == 0 ) return -1e9;
        if(dp[i - 1][j - 1] != -1) return dp[i - 1][j - 1];
        int take = (nums1[i - 1] * nums2[j - 1]) + max(0 , f(i - 1 , j - 1 , nums1 , nums2 , dp));
        int skip1 = f(i - 1 , j , nums1 , nums2 , dp);
        int skip2 = f(i , j - 1 , nums1 , nums2 , dp);
        return dp[i - 1][j - 1] = max({take , skip1 , skip2});
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m  = nums2.size();
        vector<vector<int>> dp(n  , vector<int>(m  , -1));
        return f( n  , m  , nums1 , nums2 , dp);
        /*for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){

            }
        }*/
    }
};