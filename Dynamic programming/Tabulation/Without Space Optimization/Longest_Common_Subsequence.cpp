class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[1001][1001];
        memset(dp,0,sizeof dp);
        dp[0][0] =  0;

        int ind1 = text1.size();
        int ind2 = text2.size();

        for(int i=1 ;i<=ind1 ; i++){
            for(int j = 1 ; j <=ind2 ; ++j){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[ind1][ind2];
    }
};
