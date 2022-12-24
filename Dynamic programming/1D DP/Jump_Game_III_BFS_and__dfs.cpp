class Solution {
public:
int dp[50001];
bool ans=  0;
bool solve(int i ,vector<int>& arr,vector<bool>&vis){
   
    
    if(i>=arr.size() || i<0  || vis[i]) return 0 ;
    if(dp[i]!=-1) return dp[i];
    if(arr[i]==0) return dp[i] = 1;
    
    bool f =0;
    vis[i] = 1;
    f |= solve(i+arr[i],  arr ,vis);
    f |= solve(i-arr[i] , arr ,vis ); 
    vis[i] = 0;
    return  dp[i] = f ;

}
    bool canReach(vector<int>& arr, int start) {
        queue<int>q;
        q.emplace(start);
        int n  = arr.size() ;
        vector<bool>vis(arr.size()+1,0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(arr[node]==0) return 1;
            int op1 = node+arr[node];
            int op2 = node-arr[node];
            if(op1<n && !vis[op1]){
                q.push(op1);
                vis[op1] = 1;
            }
            if(op2>-1 && !vis[op2]){
                q.push(op2);
                vis[op2] = 1 ;
            }
        }
        return 0 ;
    }
};
