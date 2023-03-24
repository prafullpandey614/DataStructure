class Solution {
public:
    int count = 0 ;
    void  dfs(int ver, vector<int>g[], vector<bool>&vis){
        if(vis[ver]){
            return  ;
        }
        vis[ver] = 1 ;
        int cnt = 0 ,pnt = 0 ;
        for(auto ch:g[ver]){
            if(!vis[ch]){
                dfs(ch,g,vis);
            }
        }
       
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
      vector<int>g[n+1];
      for(int i = 0; i <connections.size(); ++i){
          g[connections[i][0]].push_back(connections[i][1]);
          g[connections[i][1]].push_back(connections[i][0]);
      }
      vector<bool>vis(n+1,0);
      int cnt = 0 ;
      int cp = 0 ;
      for(int i =0 ; i< n ; ++i){
          if(!vis[i]){
              dfs(i,g,vis);
              cnt++;
          }
      }
      cout<<cnt<<endl;
      if(connections.size()<n-1){
          return -1;
      }
      return cnt-1;
    }
};
