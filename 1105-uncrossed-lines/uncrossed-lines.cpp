class Solution {
private:
    int LCS(int i , int j , vector<int>& nums1 , vector<int>& nums2 , vector<vector<int>>& dp){
        if(i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(nums1[i - 1] == nums2[j - 1]) return dp[i][j] = 1 + LCS(i - 1 , j - 1 , nums1 , nums2 , dp);
        return dp[i][j] = max(LCS(i - 1 , j , nums1 , nums2 , dp) , LCS(i , j - 1 , nums1 , nums2 , dp));
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        vector<int> prev(m + 1 , 0);
        //return LCS(n   , m  , nums1 , nums2 , dp);
        for(int i = 1 ; i <= n ; i++){
            vector<int> cur(m + 1 , 0);
            for(int j = 1 ; j <= m ; j++){
                if(nums1[i - 1] == nums2[j - 1])  cur[j] = 1 + prev[j - 1];
                else  cur[j] = max(prev[j] , cur[j - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }
};