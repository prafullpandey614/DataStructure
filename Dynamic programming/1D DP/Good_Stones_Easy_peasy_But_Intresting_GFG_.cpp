//Problem Link : https://practice.geeksforgeeks.org/problems/e2d156755ca4e0a9b9abf5680191d4b06e52b1a8/1 

    bool dfs(int i,vector<int> &arr,vector<int>&vis,vector<int>&dp){
        if(i>=arr.size() || i<0) return 1;
        if(dp[i]!=-1) return dp[i];
        if(vis[i]) return 0;
         vis[i] = 1;
        
       
        return dp[i] = dfs(i+arr[i],arr,vis,dp);
        
    }
    int goodStones(int n,vector<int> &arr){
        
        int count = 0 ;
        vector<int>vis(n,0),dp(n,-1);
        for(int i = 0 ; i < n ; ++i){
              if(!vis[i])
              dfs(i,arr,vis,dp);
            
        }
        for(int x:dp) count+=x==1;
        return count ;
    }  
