class Solution {
public:
    int dp[1001];
    int solve(int ind,vector<int>&prices){
        if(ind>=prices.size()){
            return 0 ;
        }
        if(dp[ind]!=-1) return dp[ind] ;

        int ans = prices[ind]+solve(2*(ind+1),prices); 
        for(int i = ind+1 ; i<=(ind+ind+2) and i<prices.size() ; ++i){
            ans =  min(ans , prices[ind]+solve(i,prices));
        }
        return dp[ind] =  ans ;
        
        
    }
    int minimumCoins(vector<int>& prices) {
         memset(dp, -1, sizeof(dp));
        return solve(0,prices);
    }
};
