class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int m = INT_MIN;
        int d = INT_MAX;
       for(int i = 0 ;i < intervals.size();++i){
           m = max(intervals[i][1],m);
           d = min(intervals[i][0],d);
           
       }
         vector<int>mp(1000055,0);
        int man =INT_MIN;
         for(int i = 0 ;i < intervals.size();++i){
             int l = intervals[i][0];
             int r = intervals[i][1];
             mp[l]+=1;
             mp[r+1]-=1;
             
       }
        // vector<int>pf(m+3,0);
        // pf[0] = 0 ;
        // int ans = INT_MIN;
        for(int i =1;i<mp.size();++i){
            mp[i]  +=mp[i-1];
            man = max(man,mp[i]);
        }
        
        return man;
    }
};
