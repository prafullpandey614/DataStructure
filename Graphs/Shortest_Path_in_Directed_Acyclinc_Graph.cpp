//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void topoSort(vector<pair<int,int>>adj[],stack<int>&st,vector<bool>&vis,int ver){
         if(vis[ver]) return ;
         vis[ver] = 1 ;
         for(auto x:adj[ver]){
             if(!vis[x.first]){
                 topoSort(adj,st,vis,x.first);
             }
         }
         st.push(ver);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(auto x:edges){
            int u = x[0];
            int v = x[1];
            int wt = x[2];
            adj[u].push_back({v,wt});
        }
        stack<int>topo ;
        vector<bool>vis(N,0);
        for(int i = 0 ;i <N ; ++i){
            if(!vis[i]) topoSort(adj,topo,vis,i);
        }
        vector<int>result(N,1e9);
        result[0]=0;
        // for(int i = 0 ; i < d)
        while(topo.size()){
            int k = topo.top();
            for(auto ch:adj[k]){
                result[ch.first] = min(result[ch.first],result[k]+ch.second);
            }
            topo.pop();
        }
        for(auto &s:result) s = s==(1e9) ? -1 : s;
        return result ;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
