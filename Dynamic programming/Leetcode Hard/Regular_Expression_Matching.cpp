class Solution {
public:
    int dp[21][21];
    bool solve(int i,int j,string &s,string &p){
        if(i<0 and j<0) return 1;
        if(i<0 and p[j]=='*'){
            return solve(i,j-2,s,p);
        }

        if(j<0 or i<0) return 0;
        if(dp[i][j] !=-1) return dp[i][j] ;
        if(p[j]=='*'){
            if(p[j-1]==s[i] or p[j-1]=='.')
            return dp[i][j] =  solve(i-1,j,s,p) or solve(i,j-2,s,p);
            return dp[i][j] =  solve(i,j-2,s,p);
        }
        if(p[j]=='.' || p[j]==s[i]){
            return dp[i][j] = solve(i-1,j-1,s,p);
        }
        return dp[i][j] =  false ;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof dp);
        return solve(s.size()-1,p.size()-1,s,p);
    }
};
