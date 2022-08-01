class Solution {
public:
    // vector<pair<int,int>>dp(,0);
    
    int recursion(int m,int n ,int d1,int d2 ,vector<vector<int>>&dp){
        if(m==d1-1 && n==d2-1){
            return dp[m][n]=1;
        }
        else if(m>=d1 || n>=d2){
            return 0 ;
        }
        if(dp[m][n]!=-1) return dp[m][n];
        return dp[m][n] = recursion(m+1,n,d1,d2, dp)+recursion(m,n+1,d1,d2, dp); //memoization
    }
    int uniquePaths(int m, int n) {
       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       
     int ans = recursion(0,0,m,n,dp);
        return ans ;
        
    }
};
