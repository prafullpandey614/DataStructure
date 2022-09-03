class Solution {
public:
    void dfs(vector<int>&ans , int n , int k ,int sz ,int curr, int prev){
        if(sz==n-1){
            ans.push_back(curr);
            return  ;
        }
        int nxt  = prev + k;
        if(nxt <10){
            dfs(ans,n,k,sz+1,curr*10+nxt,nxt);
        }
        nxt = prev- k;
        if(nxt>=0 && k!=0){
            dfs(ans,n,k,sz+1,curr*10+nxt,nxt);
        }
        
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        if(n==1){
            return {0,1,2,3,4,5,6,7,8,9};
        }
        for(int i = 1; i <=9; ++i){
            dfs(ans,n,k,0,i,i);
        }
        return ans ;
    }
};
