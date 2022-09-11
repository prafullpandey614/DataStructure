class Solution {
public:
    #define pq priority_queue
    #define pint pair<int,int>
    int m =1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
     
        vector<pair<int,int>>temp;
        for(int i = 0; i< n;++i){
            temp.push_back({efficiency[i],speed[i]});
        }
        sort(temp.begin(),temp.end(),greater<pint>());
          pq<int,vector<int>,greater<int>>p;
        long  maxi = 0;
        long sum=0;
        
        for(auto x:temp){
            
            if(p.size()==k){
                sum-=p.top();
                p.pop();
            }
            p.push(x.second);
            sum+=x.second;
            maxi = max(maxi,x.first*sum);
            
        }
        return maxi%m;
    }
};
