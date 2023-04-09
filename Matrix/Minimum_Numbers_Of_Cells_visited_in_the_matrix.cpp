class Solution {
public:
    // int dp[100001][100001];
   
    
    int minimumVisitedCells(vector<vector<int>>& grid) {
        // memset(dp,-1,sizeof dp);
         vector<vector<bool>>vis ;
        int n = grid.size();
        int m = grid[0].size();
        vis.resize(n,vector<bool>(m,0));
       
        queue<pair<int,int>>q;
        int steps = 1; 
        q.push({0,0}) ;
        vis[0][0] = 1;
        while(!q.empty()){
            int sz = q.size();
            for(int dj= 0 ; dj<sz; ++dj){
                auto [i,j] = q.front();
                q.pop();
                if(i == n-1 and j == m-1) return steps; 
                if(grid[i][j] == 0) continue;
                for(int d = grid[i][j]+i ; d>=i+1 ; --d){
                    if( d>=0 and d<n and !vis[d][j] ){

                        q.push({d,j});
                        vis[d][j] = 1;
                    }
                }
                for(int d = grid[i][j]+j ; d>=j+1; --d){
                    if( d>=0 and d<m and !vis[i][d]){

                        q.push({i,d});
                        vis[i][d] = 1;
                    }
                }
               
            }
            steps++;
        }
        return -1;
     
    }
};
