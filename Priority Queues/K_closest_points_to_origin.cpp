class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
         vector<vector<int>> ans ;
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto x:points){
            double dist = sqrt(x[0]*x[0]+x[1]*x[1]);
            pq.push({dist,{x[0],x[1]}});
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back({pq.top().second.first , pq.top().second.second});
            pq.pop();
        }
        return ans ;
        
    }
};
