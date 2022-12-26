//recursive approach
#include <bits/stdc++.h> 
int dp[1001][1001];
bool rec(int i,int target,vector<int>&arr){
    if(target==0) return 1;
    if(i==0) return target==arr[i];
    if(dp[i][target]!=-1) return dp[i][target];
    //option one take it
    bool flag1 = 0;
    if(target>=arr[i])
    flag1 = rec(i-1,target-arr[i],arr);
    //option second do not take it
    
    bool flag2 = rec(i-1,target,arr);
    return dp[i][target] = flag1 || flag2 ;
    
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    memset(dp,-1,sizeof dp);
    return rec(n-1,k,arr);
}


//Tabulation Approach
#include <bits/stdc++.h> 


bool subsetSumToK(int n, int k, vector<int> &arr) {
   

    vector<vector<bool>>dp(n+1,vector<bool>(k+1,0));
    for(int i = 0 ; i <=n  ; ++i){
        for(int j = 0 ; j <=k ; ++j){
            dp[i][j] = 0 ;
        }
    }

    for(int i = 0 ; i <n ; ++i){
        dp[i][0] = 1;
    }
    dp[0][arr[0]] = 1;
    for(int i = 1; i<n; ++i){
      for(int tar=1;  tar<=k ; ++tar){
          bool op1 = 0 ;
          if(tar>=arr[i]){
             op1 =  dp[i-1][tar-arr[i]];
          }
          dp[i][tar] = dp[i-1][tar] | op1 ; 
      }
        
    }
    
    return dp[n-1][k];
}


//Tabulation with space optimization
#include <bits/stdc++.h> 


bool subsetSumToK(int n, int k, vector<int> &arr) {
   
  vector<bool>prev(k+1,0),curr(k+1,0);
    prev[arr[0]] = 1;
    curr[0] = 1;
    prev[0]  = 1;
    for(int i = 1; i<n; ++i){
      for(int tar=1;  tar<=k ; ++tar){
          bool op1 = 0 ;
          if(tar>=arr[i]){
             op1 = prev[tar-arr[i]];
          }
          curr[tar] = prev[tar] | op1 ; 
      }
        prev = curr; 
        
    }
    
    return prev[k];
}
