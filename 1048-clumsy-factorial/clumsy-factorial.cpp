class Solution {
public:
    int clumsy(int n) {
        int ans1 = n , ans2 = 0 , choice = 3;
        for(int i = n - 1 ; i > 0 ; i-- , choice--){
            if(choice == 3) ans1 *= i;
            else if(choice == 2) ans1 /= i;
            else if(choice == 1){
                //Do the operation of minus who had ignored once
                if(ans2) ans1 = ans2 - ans1;
                ans1 += i;
                ans2 = 0;
            }
            else{
                //Ignore the operation , there may be a chance for multiplication subsequently
                ans2 = ans1;
                ans1 = i;
                choice = 4;
            }
        }
        //If There's still a term , that needs subtraction to be performed , do it
        if(ans2) return ans2 - ans1;
        return ans1;
    }
};