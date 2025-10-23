class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size() , m = nums2.size();
        vector<vector<int>> mergedArray;
        int i = 0 , j = 0;
        //Merge the common part in both array  with their sum
        while(i < n && j < m){
            if(nums1[i][0] == nums2[j][0]){
                mergedArray.push_back({nums1[i][0] , nums1[i][1] + nums2[j][1]});
                i += 1;
                j += 1;
            }
            else if(nums1[i][0] < nums2[j][0]){
                mergedArray.push_back(nums1[i]);
                i += 1;
            }
            else{
               mergedArray.push_back(nums2[j]);
               j += 1; 
            }
        }
        //Once either of the array ran out of elements , just append the remaining part of  other array to the answer
        while(i < n){
            mergedArray.push_back(nums1[i]);
            i += 1;
        }

        while(j < m){
            mergedArray.push_back(nums2[j]);
            j += 1; 
        }
        return mergedArray;
    }
};