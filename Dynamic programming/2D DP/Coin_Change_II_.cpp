// problem Link : https://leetcode.com/problems/coin-change-ii/
class Solution {
public:
    int cnt = 0;
    int dp[310][5010];
    int fun(int ind,int amount,vector<int>&coins){
        if(amount==0) return 1; //one way returned if amount becomes zero
        if(ind<0) return 0;
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int ways = 0;
        for(int coin_amount = 0; coin_amount<=amount ; coin_amount+=coins[ind]){
            ways+=fun(ind-1,amount-coin_amount,coins);
        }
        return dp[ind][amount] = ways ;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        int k = fun(coins.size()-1,amount,coins);
        return k;
    }
};
