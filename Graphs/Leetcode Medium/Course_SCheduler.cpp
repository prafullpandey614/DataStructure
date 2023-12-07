class Solution {
public:
   bool iscycle(vector<int> adj[],int n){
       vector<int>indegree(n,0);
       for(int i = 0 ; i < n ; ++i){
           for(auto ch:adj[i]){
               indegree[ch]++;
           }
       }
       queue<int>q;
       int topo = 0 ;
       for(int i = 0 ;i < n  ; ++i){
           if(indegree[i]==0) q.push(i);
       }
    //    int topo  = 0 ;
       while(!q.empty()){
           int node = q.front();
           q.pop();
           topo++;
           for(auto ch:adj[node]){
               indegree[ch]--;
               if(indegree[ch]==0) q.push(ch);
           }
       }
       return topo==n;


    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        return iscycle(adj,n);
        return true;
    }
};
