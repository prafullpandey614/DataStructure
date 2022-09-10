class Solution {
public:
      vector<vector<vector<int>>> dp;
    int rec(int ind , int buy , int k , vector<int>&p ){
        if(k==0) return  0 ;
        if(ind == p.size()) return  0; 
       
        if(dp[ind][k][buy]!=-1) return dp[ind][k][buy] ; 
         int profit = 0;
        if(buy){
            profit = max(-p[ind]+rec(ind+1,0, k, p),rec(ind+1,1,k,p));
        }
        else {
            profit = max(p[ind]+rec(ind+1,1,k-1,p),rec(ind+1,0,k,p));
        }
        return dp[ind][k][buy] = profit ;
    }
    int maxProfit(int k, vector<int>& prices) {
          dp = vector<vector<vector<int>>> (prices.size()+1, vector<vector<int>> (k+1, vector<int> (2, -1)));
       
        return rec(0,1,k,prices);
    }
};
