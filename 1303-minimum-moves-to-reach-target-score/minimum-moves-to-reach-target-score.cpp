class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int steps = 0;
        while(target != 1 && maxDoubles != 0){
            if(target % 2 == 0){
                target /= 2;
                maxDoubles -= 1;
            }
            else target -= 1;
            steps += 1;
        }
        //Whenever maxDoubles becomes zero , then steps for remaining target would be target - 1 
        //If maxDoubles doesn't become zero , then anyway target becomes 1 so , target - 1 is nullified by itself
        return steps + target - 1;
    }
};