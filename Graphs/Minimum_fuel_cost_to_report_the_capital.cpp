https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/

//Must do this Question Mind Blowing Concept
class Solution {
     private :
public:
    long long int car = 0;
    long long int seats; 
    
 long long    int dfs(int src,vector<vector<int>>&graph, vector<int>&vis){
      long long   int ppl = 0;
        if(vis[src]) return ppl;
        vis[src] = 1;
        for(auto x: graph[src]){
            if(!vis[x])
            ppl+= dfs(x,graph,vis);
            vis[x]=1;
        }
        ppl+=1;
        // if(src!=0)
        car += (ppl+(seats-1))/seats;
        return ppl ;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seat) {
       
        seats = seat ;
       long long int n = roads.size();
         vector<vector<int>>graph(n+1);
        vector<int>visited(n+1,0);
        
        for(auto &i : roads){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        long long ans = 0; visited[0]=1;
        for(auto x:graph[0]){
            ans+=dfs(x,graph,visited);
        }
        return car ;
    }
};
