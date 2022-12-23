class Solution {
public:
int ant = 0;
int dp[16][16];
    int gold(int i,int j,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 ||i>=n || j>=m || grid[i][j]==0) return 0;
        int sum = 0,ans=0;
        if(dp[i][j]!=-1) return dp[i][j] ;
        ans+=grid[i][j];
         grid[i][j] = 0;
        sum= max(sum,gold(i+1,j,grid));
        sum= max(sum,gold(i-1,j,grid));
        sum= max(sum,gold(i,j-1,grid));
        sum= max(sum,gold(i,j+1,grid));

        ant = max(ant,ans+sum);
        grid[i][j] = ans;
        return dp[i][j] = ans+sum;

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = INT_MIN;
        memset(dp,-1,sizeof dp);
        for(int i=  0; i < n  ;++i){
            for(int j = 0; j<m; ++j){
                if(grid[i][j]!=0) {
                    ans = max(ans , gold(i,j,grid));
               memset(dp,-1,sizeof dp);
                }
              
            }
        }
        return ant;
    }

};
