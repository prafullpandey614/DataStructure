class Solution {
public:
    void dfs(int i,int j,vector<vector<char>>&grid){
        int n = grid.size();
        int  m = grid[0].size();
        if(i>=n || j>=m || i<0 || j<0) return ; //edge cases
        if(grid[i][j]=='2' || grid[i][j]=='0') return ; // checking if visited then no need to traverse again
        grid[i][j] = '2'; // Mariking Visited by changing it's value to 2
        dfs(i+1,j,grid);        //Up DFS
        dfs(i-1,j,grid);        // DOwn DFS
        dfs(i,j+1,grid);        //Left DFS
        dfs(i,j-1,grid);          //RIght DFS
        return ;



        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int  m = grid[0].size();
        int cc = 0; 
       //This Question is based on the concept of Connected Components of Graph
//       We are Traversing through grid and checking how much times we have called DFS 
        for(int i = 0 ;i<n ;++i){
            for(int j = 0 ; j < m ;++j){
                    if(grid[i][j]!='2' && grid[i][j]!='0')
                    {  
                      dfs(i,j,grid);
                      cc++;
                    }
                
            }
        }
        return cc ;
    }
};
