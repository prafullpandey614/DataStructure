class Solution {
public:
    int recursion(int ind,int k,vector<int>v){
        if(v.size()==1){
            return v[0];
        }
        int deletion_index = (ind+k)%(v.size());
        v.erase(v.begin()+deletion_index);
        return recursion(deletion_index,k,v);
        
    }
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i =  1 ; i <= n ; ++i) v.push_back(i);
        return recursion(0,k-1,v);
    }
};
