class Solution {
public:
    
    int rec(int ind, bool buy , vector<int>&p , int dp[][2]){
        if(ind==p.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        int profit  = 0,profit2=0 ;
        if(buy){
            profit  = max(-p[ind]+ rec(ind+1,false,p,dp),rec(ind+1,true,p,dp)); } //buy that day ( if you are buying then obviously you have to spend money that's why I subtracted -p[ind] )
        else{
            profit = max( p[ind]+ rec(ind+1,true,p,dp), rec(ind+1,false,p,dp)); //don't buy that day
        }
        return dp[ind][buy] = profit;
        
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>v(prrices.size(),vector<int>(1,-1));
        int dp[prices.size()][2];
        for(auto x:dp){
            x[0] = -1;
            x[1] = -1 ;
        }
     int k = rec(0,true,prices,dp);
        return  k;
    }
};
