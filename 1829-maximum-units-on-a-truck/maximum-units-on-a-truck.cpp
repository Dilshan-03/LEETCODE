class Solution {
private:
    static bool comp(vector<int>& a , vector<int>& b){
        return a[1] < b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() , boxTypes.end() , comp);

        int n = boxTypes.size();
        int i = n - 1;
        int units = 0;
        while(i >= 0){
            int box = 0;
            if(truckSize == 0) break;
            if(truckSize >= boxTypes[i][0]){
                box = boxTypes[i][0];
                truckSize -= box;
            }
            else{
                box = truckSize;
                truckSize = 0;
            }
            units += (box * boxTypes[i][1]);
            i--;
        }
        return units;
    }
};