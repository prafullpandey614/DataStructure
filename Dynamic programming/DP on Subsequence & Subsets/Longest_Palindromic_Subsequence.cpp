//recursive
class Solution {
public:
int dp[1001][1001];
    int lcs(int i,int j, string &s,string &rev){
        if(i>=s.length() || j>=rev.size()) return  0 ;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==rev[j]){
            return dp[i][j] = 1+lcs(i+1,j+1,s,rev);
        }
        else return dp[i][j] = max(lcs(i+1,j,s,rev),lcs(i,j+1,s,rev));
    }
    int longestPalindromeSubseq(string s) {
        string rev=  s;
        memset(dp,-1,sizeof(dp));
        reverse(s.begin(),s.end());
        return lcs(0,0,s,rev);
    }
};
//tabulation
class Solution {
public:
// int dp[1001][1001];
    
    int longestPalindromeSubseq(string s) {
        string rev=  s;
        int n  =s.length();
        int dp[n+1][n+1]  ;
        memset(dp,0,sizeof(dp));
        // dp[0][0] = 0 ;
        reverse(s.begin(),s.end());
        
        // if(s[0]==rev[0]) dp[0][0] = 1;
        for(int i  = 1 ; i<=n ; ++i){
            for(int j = 1 ;j <= n  ;++j){
                if(s[i-1]==rev[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // memset(dp,-1,sizeof(dp));
        
        return dp[n][n];
        // return lcs(0,0,s,rev);
    }
};
