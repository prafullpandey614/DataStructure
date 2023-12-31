class Solution {
public:
    unordered_map<char,vector<pair<char,int>>>mp;
    bool flag = 0; 
    long long solve(int ind,string &source,string &target ){
        
        if(ind==source.size()) {
            return 0 ;
        }
        
        if(source[ind]!=target[ind]){
            string key = "";
            key.push_back(source[ind]); 
            // key.push_back(target[ind]);
            vector<pair<char,int>>cmp = mp[source[ind]]
            long long ans = INT_MAX ;
            bool gb = 0 ;
            for(auto x:cmp){
               
                int k = x.first==target[ind] ? 1 : 0 ;
                ans = min(ans,x.second+solve(ind+k,source,target));
               
                
            }    
            if(ans==0) return -1;
            if(mp.find(key)!=mp.end()){
                
                return mp[key]+solve(ind+1,source,target);
            }
            flag = 1;
            return -1;
        }
        return solve(ind+1,source,target);
        
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        for(int i = 0 ;i < cost.size() ; ++i){
             string key = "";
            key.push_back(source[i]); 
            // key.push_back(target[i]);
            mp[key].push_back({target[i],cost[i]});
        }
        if(flag) return -1;
        return solve(0,source,target);
    }
};
