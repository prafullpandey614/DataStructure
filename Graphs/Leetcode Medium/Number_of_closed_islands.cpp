class Solution {
public:
bool dfs(int i , int j ,vector<vector<int>>& grid ){
    if(grid[i][j]==1 || grid[i][j]==-1) return 1;
    int n = grid.size();
    int m = grid[0].size();
    if(i<=0 || j<=0 || i>=n-1 || j>=m-1) return  0; 
    
    grid[i][j] = -1;
    bool flag = 1;
    flag &= dfs(i+1,j,grid);
    flag &= dfs(i,j+1,grid);
    flag &= dfs(i,j-1,grid);
    flag &= dfs(i-1,j,grid);
    // grid[i][j] = 0 ;
    return flag;
}
    int closedIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0; 
    for(int i = 1 ; i < n -1 ;++i){
        for(int j = 1 ; j < m-1  ;++j){
            if(grid[i][j]==0){
               if(dfs(i,j,grid)) cnt++;
            }
        }
    }
    return cnt ;
    }
};
