class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n,m;
        n = grid.size();
        m = grid[0].size();
        long long int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[n-1][m-1] =1 ;
        for(int i = n-1; i >=0  ; --i){
            for(int j = m-1 ; j >= 0 ; --j){
                if(i==n-1 && j== m-1) continue ;
                if(grid[i][j]==1) {
                    dp[i][j]==0;
                }
                else dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        if(grid[n-1][m-1]==1) return  0 ;
        if(grid[0][0]==1) return 0;
        return dp[0][0];
    }
};
