class Solution {
public:
    vector<int> tps(vector<int> adj[],int n){
       vector<int>indegree(n,0);
       for(int i = 0 ; i < n ; ++i){
           for(auto ch:adj[i]){
               indegree[ch]++;
           }
       }
       queue<int>q;
    //    int topo = 0 ;
    vector<int>topo ;
       for(int i = 0 ;i < n  ; ++i){
           if(indegree[i]==0) q.push(i);
       }
    //    int topo  = 0 ;
       while(!q.empty()){
           int node = q.front();
           q.pop();
           topo.push_back(node);
           for(auto ch:adj[node]){
               indegree[ch]--;
               if(indegree[ch]==0) q.push(ch);
           }
       }
       vector<int>ansl ;
       return topo.size()==n ?  topo : ansl;


    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(auto edge : prerequisites)
            adj[edge[1]].push_back(edge[0]);
        return tps(adj,numCourses);
    }
};
