class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>winn,lostone;
        for(int i = 0 ; i < matches.size(); ++i){
               
                lostone[matches[i][1]]++; 
            winn[matches[i][0]]++;
            
        }
        vector<vector<int>>ans; vector<int>ts,gs;
        for(auto x:winn){
            
           if(lostone[x.first]==0){
               ts.push_back(x.first);
           }
          
        }
        
        for(auto x:lostone){
            if(x.second==1) gs.push_back(x.first);
        
            
        }
        sort(ts.begin(),ts.end());;
        sort(gs.begin(),gs.end());
        ans.push_back(ts);
        ans.push_back(gs);
        return ans ;
    }
};
