class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int steps = 0;
        while(target != 1 && maxDoubles != 0){
            //if(maxDoubles == 0) steps += target - 1;
            if(target % 2 == 0){
                target /= 2;
                maxDoubles -= 1;
            }
            else target -= 1;
            steps += 1;
        }
        return steps + target - 1;
    }
};