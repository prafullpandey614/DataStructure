string dfs(int i,int j,vector<vector<int>>& grid,string S){
      int n = grid.size();
      int m = grid[0].size();
      if(i<0 ||  j< 0 || i>=n || j>=m) return "O" ;
      if(grid[i][j]==0) return "0";
      grid[i][j] = 0;
      string down = dfs(i+1,j,grid,"D");
      string up =  dfs(i-1,j,grid,"U");
      string left =   dfs(i,j-1,grid,"L"); 
      string right = dfs(i,j+1,grid,"R");
      return S+down+up+left+right;
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
         int n = grid.size();
      int m = grid[0].size();
      set<string>st;
      for(int i = 0 ; i < n ; ++i){
          for(int  j = 0 ; j < m ; ++j){
              if(grid[i][j]==1){
                string path  =  dfs(i,j,grid,"S");
                st.insert(path);
              }
          }
      }
      return st.size();
    }
