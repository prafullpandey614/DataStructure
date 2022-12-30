https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
      
      
        int n = str1.size();
        int m = str2.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        string ans = "";
        for(int i = 1 ; i<=n ; ++i){
            for(int j = 1; j <=m ; ++j){
                if(str1[i-1]==str2[j-1]){
                    
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else {                    
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i = str1.size() ,j = str2.size();
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    ans.push_back(str1[i-1]),i--;
                }
                else ans.push_back(str2[j-1]),j--;
            }
        }
        while(j>0) ans.push_back(str2[j-1]),--j;
        while(i>0) ans.push_back(str1[i-1]),--i;
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};
