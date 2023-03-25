class Solution {
public:
    long long ans =0 ;
    void solve(int ver,vector<int>g[],vector<bool>&vis,int n){
        vis[ver]=1;
        ans++;
        int unr = 0 ;
        for(auto ch:g[ver]){
           
            if(!vis[ch])
            solve(ch,g,vis,n), unr++;;
        }
        
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>g[n];
        ans = 0; 
        for(auto x:edges){
            g[x[0]].push_back(x[1]);
            g[x[1]].push_back(x[0]);
        }
        long long int sum =0 ;
        vector<bool>vis(n,0);
        vector<int>v ;
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                ans = 0 ;
                solve(i,g,vis,n);
               
                sum+=ans ;
                v.push_back(ans);
            }
          
        }
      long long  ans = 0 ;
        // cout<<sum<<endl;
        for(int i = 0; i<v.size(); ++i){
            // cout<<v[i]<<endl;
            sum-=v[i];
            
            if(sum>0)
            ans += (sum)*1LL*v[i];
           
        }
        return ans;
    }
};
