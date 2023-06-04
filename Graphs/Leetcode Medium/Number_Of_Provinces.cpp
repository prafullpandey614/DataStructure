class Solution {
public:
    void dfs(int ver,vector<int>grid[],vector<bool>&vis){
        // if(i<0 or j<0 or j>=grid.size() or i>grid.size() or grid[i][j]==0) return ;
        // grid[i][j] = 0 ;
        if(vis[ver]) return ;
        vis[ver]=1;
        for(auto ch:grid[ver]){
            dfs(ch,grid,vis);
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adj[n+1];
        for(int i =0 ; i<n ; ++i){
            for(int j= 0 ; j < n ; ++j){
                if(isConnected[i][j]==1 and i!=j){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        vector<bool>vis(n+1);
        int ans = 0 ;
        for(int i = 1; i<=n ; ++i){
            if(!vis[i]){
                // cout<<i<<" ";
                dfs(i,adj,vis);
                ans++;
            }
        }
        return ans ;
    }
};
