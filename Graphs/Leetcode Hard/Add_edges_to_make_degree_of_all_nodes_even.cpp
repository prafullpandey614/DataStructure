Problem Link : https://leetcode.com/problems/add-edges-to-make-degrees-of-all-nodes-even/description/
#define pb push_back
class Solution {
public:
   
    bool isPossible(int n, vector<vector<int>>& edges) {
        // vector<int>g[n+1];
        vector<int>degree(n+1);
        set<pair<int,int>>st;
        for(int i = 0 ; i <  edges.size() ; ++i){
            // g[edges[i][0]].push_back(edges[i][1]);
            // g[edges[i][1]].push_back(edges[i][0]);
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
            st.insert({edges[i][0],edges[i][1]});
            st.insert({edges[i][1],edges[i][0]});

        }
        vector<int>odd;
        for(int i = 1; i <=n ;++i){
            if((degree[i])&1) odd.pb(i);
        }
        if(odd.size()>4 || odd.size()&1) return 0;
        if(odd.size()==0) return  1;
        if(odd.size()==2){
            // cout<<"Case 2"<<endl;
           if(st.find({odd[0],odd[1]})==st.end() || st.find({odd[1],odd[0]})==st.end()){
               return 1;
           }
           for(int i = 1 ; i<=n ; ++i){
               if(st.find({i,odd[0]})==st.end() && st.find({i,odd[1]})==st.end()){
                   return 1;
               }
           }
            return 0;
        }
        if(odd.size()==4){
            int a = odd[0];
            int b = odd[1];
            int c = odd[2];
            int d = odd[3];
            if(st.find({a,b})==st.end() && st.find({c,d})==st.end()){
                return 1;
            }
            if(st.find({a,c})==st.end() && st.find({d,b})==st.end()){
                return 1;
            }
            if(st.find({c,b})==st.end() && st.find({a,d})==st.end()){
                return 1;
            }
        }
        return  0;
    }
};
