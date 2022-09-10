class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =  0 ;
        int mini_left_stock = prices[0];
        for(int i = 1; i < prices.size();++i){
            int cost = prices[i]-mini_left_stock a;
            profit = max(profit,cost);
            mini_left_stock = min(mini_left_stock,prices[i]);
        }
        return profit ;
    }
};
