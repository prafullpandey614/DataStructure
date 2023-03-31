class Solution {
public:
const int mod = 1e9+7;
    int solve(int i,int  j,int ct,vector<vector<int>>&pf,vector<vector<vector<int>>>&dp){
        if(pf[i][j] ==0) return 0 ;
        if(ct<=0) return 1; 
        int n = pf.size()-1;
        int m = pf[0].size()-1;
        if(dp[i][j][ct]!=-1) return dp[i][j][ct];
        int ans = 0;
        for(int nr = i+1 ; nr<n; nr++){
            if(pf[i][j]-pf[nr][j]>0){
                ans= (ans+ solve(nr,j,ct-1,pf,dp))%mod;
            }
        }
         for(int nc = j+1 ; nc<m; nc++){
            if(pf[i][j]-pf[i][nc]>0){
                ans = (ans+solve(i,nc,ct-1,pf,dp))%mod;
            }
        }

        return dp[i][j][ct] = ans;

    }
    int ways(vector<string>& pizza, int k) {
       
        int n = pizza.size();
        int m = pizza[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        vector<vector<int>>pf(n+1,vector<int>(m+1,0));
       
        int ds = 0 ;
        
        
       
        for(int i = n-1 ; i >=0 ; --i){
            for(int j = m-1; j >=0; --j){
                if(pizza[i][j]=='A'){
                    ds = 1 ;
                }
                else ds = 0 ;
                pf[i][j] = ds+pf[i+1][j]+pf[i][j+1]-pf[i+1][j+1];
            }
        }
        //  return 1;
        return solve(0,0,k-1,pf,dp);
    }
};
