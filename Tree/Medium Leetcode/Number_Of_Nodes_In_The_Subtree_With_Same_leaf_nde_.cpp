class Solution {
public:
    vector<int>ans;

    int dfs(int ver, vector<int> edges[],string &lab,vector<bool>&vis,vector<int>&freq){
        int count = 1;
        // if(vis[ver]) return ans[ver];
        vis[ver]=1;
        int prev_freq = freq[lab[ver]-'a'];
        freq[lab[ver]-'a']++;
       for(auto x:edges[ver]){
           if(!vis[x])
           ans[ver]+=dfs(x,edges,lab,vis,freq);
       }
       ans[ver] = freq[lab[ver]-'a']-prev_freq;

       return ans[ver];
    
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        ans.resize(n,0);
        vector<bool>vis(n+1,0);
        vector<int>prev(26,0);
        vector<int>adj[n+1];
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        int d = dfs(0,adj,labels,vis,prev);
        // cout<<0<<" "<<ans[0]<<endl;;
        return ans ;

    }
};
