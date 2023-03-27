class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&grid){
        
        n = grid.size();
        m = grid[0].size();
        if(i==n-1 and j==m-1){
            return grid[i][j];
        }
        if(i<0 or j<0 or i>=n or i>=m){
            return INT_MAX ;
        }   

        int op1 = solve(i+1,j,grid);        
        int op2 = solve(i,j+1,grid);        

        return grid[i][j] + min(op1,op2);

    }
    int minPathSum(vector<vector<int>>& grid) {





        // int n,m;
        // n = grid.size();
        // m = grid[0].size();
        // int dp[n+1][m+1];
        // // memset(dp,0,sizeof(dp));
        
        //     for(int j = 0 ; j <=m ;  ++j){
        //         dp[0][j] = 1e3;
        //     }
        //     for(int j = 0 ; j <=m ;  ++j){
        //         dp[n][j] = 1e3;
        //     }
        //     for(int i = 0 ; i <=n ;  ++i){
        //         dp[i][0] = 1e3;
        //     }
        //     for(int i = 0 ; i <=n ;  ++i){
        //         dp[i][m] = 1e3;
        //     }
        // dp[n-1][m-1] =grid[n-1][m-1] ;
        // for(int i = n-1 ; i>=0 ; --i){
        //     for(int  j= m-1 ; j>=0 ; --j){
        //         if(i==n-1 && j==m-1) continue ;
        //         dp[i][j]=0;
        //         dp[i][j] = grid[i][j];                
        //         dp[i][j] += min(dp[i+1][j],dp[i][j+1]);
        //     }
        // }
        // return dp[0][0];
    }
};
