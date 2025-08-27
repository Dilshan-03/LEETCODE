class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
       int n = prices.size();
       //All you need to buy is 2 chocolates , so just find the 2 cheapest chocolates and check for appropriate conditions
       int cheap1 = INT_MAX , cheap2 = INT_MAX;
       for(int i = 0 ; i < n ; i++){
        if(prices[i] <= cheap1){
            cheap2 = cheap1;
            cheap1 = prices[i];   
        }
        else if(prices[i] < cheap2) cheap2 = prices[i];
       }

       if(money - (cheap1 + cheap2) >= 0) money -= (cheap1 + cheap2);
       return money;

       
    }
};