class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        sort(items1.begin() , items1.end());
        sort(items2.begin() , items2.end());
        int n = items1.size() , m = items2.size();
        vector<vector<int>> mergedArray;
        int i = 0 , j = 0;
        //Merge the common part in both array  with their sum
        while(i < n && j < m){
            if(items1[i][0] == items2[j][0]){
                mergedArray.push_back({items1[i][0] , items1[i][1] + items2[j][1]});
                i += 1;
                j += 1;
            }
            else if(items1[i][0] < items2[j][0]){
                mergedArray.push_back(items1[i]);
                i += 1;
            }
            else{
               mergedArray.push_back(items2[j]);
               j += 1; 
            }
        }
        //Once either of the array ran out of elements , just append the remaining part of  other array to the answer
        while(i < n){
            mergedArray.push_back(items1[i]);
            i += 1;
        }

        while(j < m){
            mergedArray.push_back(items2[j]);
            j += 1; 
        }
        return mergedArray;
    }
};