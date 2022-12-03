class Solution {
public:
    static bool cmp(pair<int,char>&p1,pair<int,char>&p2){
        return p2.first<p1.first ;
    }
    string frequencySort(string s) {
       priority_queue<pair<int,char>>pq;
       unordered_map<char,int>mp;
       for(auto x:s){
           mp[x]++;
       }
       for(auto x:mp){
           pq.push({x.second ,x.first});
       }
      string ans= "";
        while(!pq.empty()){
             auto t = pq.top();
           
            pq.pop();
             for(int i = 0 ; i < t.first ; ++i){
                 ans.push_back(t.second);
             }
        }
       return ans ;
    }
};
