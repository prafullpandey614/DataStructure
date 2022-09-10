class Solution {
public:
    int rec(int ind ,int buy , int cap , vector<int>&p , int dp[][2][3]){
        if(cap==0) return 0;
        if(ind==p.size()) return  0 ; 
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit =  0 ;
        if(buy){
            profit = max(-p[ind]+rec(ind+1,0,cap,p,dp), rec(ind+1,1,cap,p,dp) );
        }
        else {
            profit =  max(p[ind]+rec(ind+1,1,cap-1,p,dp),rec(ind+1,0,cap,p,dp));
        }
        return  dp[ind][buy][cap] =  profit ;
    }
    int maxProfit(vector<int>& prices) {
        int dp[prices.size()][2][3];
        for(auto x:dp){
            x[0][0] = -1 ;
            x[0][1] =-1;
            x[0][2] =-1;
            x[1][0] =-1;
            x[1][1] = -1;
            x[1][2] =-1;
        }
        return rec(0,1,2,prices,dp);
    }
};
