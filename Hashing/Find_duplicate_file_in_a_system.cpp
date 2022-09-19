class Solution {
public:
    
    #define pb push_back
     unordered_map<string,vector<string>>mp;
    vector<vector<string>> findDuplicate(vector<string>& paths) {
       
        vector<vector<string>>ans;
        for(string s:paths){
            string ind = "";
            string root_d ;
            for(int i = 0; i <  s.size() ;++i){
                if(s[i]!=' ') 
                ind.pb(s[i]);
                 if(s[i]!=' ') 
                root_d = ind;
                
                if(s[i]==' '){
                    ind.pb('/');
                    i++;
                   
                    while(s[i]!='('){
                        ind.pb(s[i++]);
                        
                    }
                    
                    string data ="";
                    while(s[i]!=')'){
                        data.pb(s[i++]);
                    }
                    data.pb(')');
//                 
                    mp[data].pb(ind);
                }
                ind = root_d;
            }
            
        }
        
       
        for(auto x:mp){
          vector<string>v;
            if(x.second.size()>1){
            for(auto f:x.second){
                v.pb(f);
            }
            }
            if(v.size())
            ans.pb(v);
          
        }
        return ans;
    }
};
