class Solution {
public:
    int dp[501];
    int solve(vector<int>& arr,int ind,int k){
        if(ind==arr.size()){
            return 0 ;
        }
        if(dp[ind]!=-1) return dp[ind];
        int len = 0;
        int ans = INT_MIN ;
        int n = arr.size();
        int maxi = INT_MIN;
        int res ;
        for(int j = ind; j<min(n,ind+k); ++j){
            len++;
            maxi = max(maxi,arr[j]);
            res = maxi*len+solve(arr,j+1,k);
            ans = max(ans,res);
        }
        return dp[ind] =  ans ;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof dp);
       return solve(arr,0,k);
    }
};
