class Solution {
public:
    bool isPossible(vector<int>& a) {
        vector<pair<int,int>>v = {{a[0],1}};
        // v.push_back({a[0],1});
        if(a.size()<3) return false;
        
        for(int i =1 ;i<a.size();++i){
            int sz = v.size();
            int end=  v[sz-1].first;
            if(a[i]==end+1){
                v[sz-1].first++;
                v[sz-1].second++;
            }
            
          else  if(a[i]==end){
                bool found = 0;
                for(int j= sz-2 ; j >= 0; --j){
                    if(a[i]==v[j].first+1){
                        found = 1;
                        v[j].first++;
                        v[j].second++;
                        break ;
                    }
                }
                if(!found){
                    v.push_back({a[i],1});
                }
            }
            else {
                v.push_back({a[i],1});
            }
        }
        for(auto &x:v){
            if(x.second<3) return 0;
        }
        return 1;
        
    }
};
