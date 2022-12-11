class Solution {
public:
     
    vector<bool>vis;
    int ans = INT_MIN ;
    void dfs(int ver, vector<int>g[],int k,vector<int>& vals){
        if(vis[ver]) return ;
        vis[ver] = 1;
        vector<int>v ;
        unordered_map<int,int>mp;
        for(auto x:g[ver]){
            v.push_back(vals[x]);
            mp[vals[x]] = x;
        }
        
        sort(v.begin(),v.end(),greater<int>());      
        int cnt = 0 ;
        int sum = vals[ver];
        ans = max(ans,sum);
        // cout<<"Here su m "<<sum<<endl;
        
        for(auto child:v){
             // if(cnt>k+1) break ;
             // sum+=child ;
             cnt++;
             // cout<<child<<" ";
             sum+=child ;
            ans = max(ans,sum);
             if(cnt==k) break;
        }
        ans = max(ans,sum);
        for(auto child:g[ver]){
            dfs(child,g,k,vals);
        }
        
        
        
    }
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        vector<int>g[vals.size()];
        vis.resize(vals.size(),0);
        
        for(auto x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        for(int i = 0 ; i < vals.size();++i){
            if(!vis[i]){
                 dfs(i,g,k,vals);
            }
        }
       
        return ans ;
    }
};
