class Solution {
public:
    long long dp[100001];
    long long dfs(int ind,vector<vector<int>>&q){
        if(ind>=q.size()) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind] = max(dfs(ind+1,q),q[ind][0]+dfs(ind+q[ind][1]+1,q));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,questions);
    }
};
