class Solution {
public:
    static bool comp(pair<int,int>&p1,pair<int,int>&p2){
        return p1.second<p2.second ;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>coll(n) ;
        for(int i = 0 ; i < n ; ++i){
            coll[i] = {profits[i],capital[i]};
        }
        sort(coll.begin(),coll.end(),comp);
        priority_queue<int>pq;
        int i = 0 ;
        while(k--){
            while(i<n && w>=coll[i].second) pq.push(coll[i++].first);
            if(!pq.empty()){
                w+=pq.top(),pq.pop();
            }
        }
        return w ;
    }
};
