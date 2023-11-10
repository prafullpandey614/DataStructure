class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int>v;
        unordered_map<int,int>mp;
        unordered_map<int,vector<int>>hmp;
        for(int i = 0 ; i < adjacentPairs.size() ; ++i){
            mp[adjacentPairs[i][0]]++;
            mp[adjacentPairs[i][1]]++;
            hmp[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            hmp[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        int st = -1 ,end = -1; 
        for(auto x:mp){
            if(x.second==1) {
                if(st==-1) st = x.first ;
                end =  x.first ;
            }
        }
        cout<<end<<" "<<st<<endl;
        v.push_back(st);
        queue<int>q;
        set<int>s;
        s.insert(st);
        int sz = 1 ;
        q.push(hmp[st][0]);
        while(q.size()){
            int k = q.front();
            q.pop();
            if(s.find(k) !=s.end()) continue ;
            for(int x:hmp[k]){
                if(s.find(x)==s.end()) {
                    q.push(x);
                    v.push_back(x);
                }
            } 
            s.insert(k);
           
        }
        v.push_back(end);
        return v;
    }
};
