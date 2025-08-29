class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while(num > 0){
           //If it's even , then divide it by 2
           if(num % 2 == 0) num = num / 2;
           //If it's odd , subtract it by 1
           else num = num - 1;
           steps += 1;
        }
        return steps;
    }
};