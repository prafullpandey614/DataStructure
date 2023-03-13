class Solution {
public:
    
    int change(int amount, vector<int>& coins) {
        int dp[amount+1] ; //each index of this dp array represents the number of commbinations possible to make that amount for e.g. dp[4] = no. of ways to make 4 
        memset(dp,0,sizeof dp); 
        dp[0] = 1 ;//if amount is zero then there's single way of doing it do not select any coin 
        for(int i = 0; i <coins.size() ;++i){
            // take each coin and use it to make all the possible amounts
            //this 2nd loop starts from the current coin because minimum amount you can make with this coin is coins[i] only
            for(int amnt = coins[i] ; amnt <=amount ; ++amnt){
                if(amnt>=coins[i]){
                    dp[amnt] +=dp[amnt-coins[i]]; //just add all the ways
                }
            }
        }
        return dp[amount] //return the ways to make amount == amount;
    }
};
