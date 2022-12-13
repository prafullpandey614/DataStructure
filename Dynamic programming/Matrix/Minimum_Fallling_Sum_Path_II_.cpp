class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int dp[n+1][m+1];
  
            for(int j = 0 ; j <m ; ++j){
               dp[0][j]=matrix[0][j];
            }

        for(int i = 1; i < n ; ++i){
            for(int j = 0; j <m  ; ++j){
               int cost=0,ans=INT_MAX;
                for(int col=0;col<m;col++)
                {
                    if(col!=j)
                    {
                        cost = matrix[i][j] +dp[i-1][col];
                        ans=min(ans,cost);
                    }
                }
                dp[i][j]=ans;
             
            }
        }
            int ans = INT_MAX;
       
            for(int j = 0 ; j < m ; ++j){
                ans = min(dp[n-1][j],ans);
            }
    
        return ans ;
    }
};
