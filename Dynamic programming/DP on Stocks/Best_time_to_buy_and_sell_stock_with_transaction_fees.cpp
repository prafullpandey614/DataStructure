class Solution {
public:
    int dp[1000000][2];
    int solve(int i,bool own,int fee, vector<int>&prices){
        if(i==prices.size()){
            return  0;
        }
        if(dp[i][own]!=-1) return dp[i][own];
        int op1 = solve(i+1,own,fee,prices);
        if(own){
           
            int op2 = prices[i]+ solve(i+1,0,fee,prices)-fee;
            return dp[i][own] =  max(op1,op2);
        }
        else{
            
            int op2 = solve(i+1,1,fee,prices)-prices[i];
            return dp[i][own]  = max(op1,op2);
        }
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof dp);
        return solve(0,0,fee,prices);
    } 
};
