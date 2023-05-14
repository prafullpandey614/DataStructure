#define ll long long
  ll solve(int i,int f,vector<int>&A,vector<vector<ll>>&dp){
      if(i<0){
          return 0;
      }
      if(dp[i][f]!=-1)return dp[i][f];
      if(f==1){
          return dp[i][f]=max(A[i]+solve(i-1,1,A,dp),solve(i-1,0,A,dp));
      }
      else{
          return dp[i][f]=A[i]+solve(i-1,1,A,dp);
      }
      
  }
    long long findMaxSubsetSum(int N, vector<int> &A) {
        // code here
        vector<vector<ll>>dp(N,vector<ll>(2,-1));
        return max(solve(N-1,0,A,dp),solve(N-1,1,A,dp));
    }
