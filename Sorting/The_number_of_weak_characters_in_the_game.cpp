class Solution {
public:
   static bool sortt(vector<int>&a,vector<int>&b){
       if(a[0]!=b[0]){
           return (a[0]>b[0]); // sorting according to first element
       }
        return a[1]<b[1]; //sorting according to second element
    }
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        
        sort(p.begin(),p.end(),sortt);
        int count = 0 , mdef = INT_MIN ;
        for(int i = 0; i < p.size() ;++i){
            if(p[i][1]<mdef) count++;
            else mdef  = max(mdef,p[i][1]);
        }
        return count ;
    }
};
