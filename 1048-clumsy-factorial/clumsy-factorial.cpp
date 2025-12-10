class Solution {
public:
    int clumsy(int n) {
        int ans1 = n , ans2 = 0 , choice = 3;
        for(int i = n - 1 ; i > 0 ; i-- , choice--){
            if(choice == 3) ans1 *= i;
            else if(choice == 2) ans1 /= i;
            else if(choice == 1){
                if(ans2) ans1 = ans2 - ans1;
                ans1 += i;
                ans2 = 0;
            }
            else{
                ans2 = ans1;
                ans1 = i;
                choice = 4;
            }
        }
        if(ans2) return ans2 - ans1;
        return ans1;
    }
};