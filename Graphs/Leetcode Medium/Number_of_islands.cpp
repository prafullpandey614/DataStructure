class Solution {
public:

    void dfs(vector<vector<char>>& grid,int i,int j){
        int n,m;
        n = grid.size();
        m  =grid[0].size();
        
        if(i>=n || j>=m) return ;
        if(i<0 || j<0 || grid[i][j]!='1' ) return ;
       
        grid[i][j] = '0';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);


    }
    int numIslands(vector<vector<char>>& grid) {
        int count_of_Islands  = 0 ;
        int n = grid.size(),m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; ++j){
                if(grid[i][j]=='1'){
                    dfs(grid,i,j);
                    count_of_Islands++;
                }
            }
        }
        return count_of_Islands ;
    }
};
