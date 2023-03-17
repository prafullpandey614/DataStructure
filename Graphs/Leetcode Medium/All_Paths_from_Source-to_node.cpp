class Solution {
public:
    int n ;
    vector<vector<int>>ans ;
    void dfs(int ver,vector<int>&path,vector<int>g[],vector<bool>&vis){
        if(vis[ver]) return ;
        if(ver==n) {ans.push_back(path);return;}
        vis[ver]= 1;
        for(auto child:g[ver]){
            if(!vis[child]){
                path.push_back(child);
                dfs(child,path,g,vis);
                path.pop_back();
            }
        }
        vis[ver] = 0 ;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>g[graph.size()+1];
        n = graph.size()-1;
        int i = 0 ;
        for(auto x:graph){
            for(auto y:x){
                g[i].push_back(y);
            }
            i++;
        }
        vector<bool>v(n+1,0);
        vector<int>p={0};
        dfs(0,p,g,v);
        return ans;
    }
};
