class Solution {
private:
    static bool comp(vector<int>& a , vector<int>& b){
        return a[1] < b[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //sort the boxTypes according to no of units in a ascending order 
        sort(boxTypes.begin() , boxTypes.end() , comp);

        int n = boxTypes.size();
        int i = n - 1;
        int units = 0;
        //Iterate from the end for maximum units
        while(i >= 0){
            int box = 0;
            if(truckSize == 0) break;
            //If specific box in lesser than truck size than acquire them or else acquire only upto truckSize
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