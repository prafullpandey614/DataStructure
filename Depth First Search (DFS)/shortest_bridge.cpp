class Solution {
public:
vector<vector<int>>first;
void dfs(int i ,int j,vector<vector<int>>&grid){
    if(i>=grid.size() or j>=grid[0].size() or i<0 or j<0 or grid[i][j]==0) {
        return ;
    }

    first.push_back({i,j});
     if(grid[i][j]==1) {
       grid[i][j]=0;
    }
    
    dfs(i+1,j,grid);
    dfs(i,j+1,grid);
    dfs(i-1,j,grid);
    dfs(i,j-1,grid);
   
    
}
 int exp(int i,int j,vector<vector<int>>&grid){
     if(i>=grid.size() or j>= grid[0].size() or i<0 or j<0 or grid[i][j]==2) return 1e7;

     if(grid[i][j]==1) return 0;
     grid[i][j] = 2;
     int op1 = exp(i+1,j,grid);
     int op2 = exp(i,j+1,grid);
     int op3 = exp(i,j-1,grid);
     int op4 = exp(i-1,j,grid);
     cout<<op1<<" "<<op2<<" "<<op3<<" "<<op4<<endl;
     return 1+ min(op1,min(op2,min(op3,op4)));

 }
    int shortestBridge(vector<vector<int>>& grid) {

        for(int i = 0 ;i < grid.size(); ++i){
            for(int j = 0 ;j < grid[0].size(); ++j){
                if(grid[i][j]==1){
                    dfs(i,j,grid);
                    break;
                }
            }
        }

        int ans = INT_MAX;
        for(auto x:first){
            // cout<<x[0]<<" "<<x[1]<<endl;
            ans = min(ans,exp(x[0],x[1],grid));
            // cout<<ans<<" ";
        }
        return ans ;
    }
};
