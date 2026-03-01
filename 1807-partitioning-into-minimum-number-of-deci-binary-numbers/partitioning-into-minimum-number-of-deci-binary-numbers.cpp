class Solution {
public:
    int minPartitions(string n) {
        int maxi = 0;
        //Whole idea is decompose the number of all 0 , then count the number of steps it takes . The maximum digit takes longer number of steps to reach 0 . Since we are subtracting with 1 , the maximum digit' reduction to 0 takes that much number of ones
        for(auto chr : n){
            maxi = max(maxi , chr - '0');
        }
        return maxi;
    }
};