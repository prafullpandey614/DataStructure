class Solution {
public:
    int dp[501][501];
     int opCount(int i,int j, string &word1,string &word2){
         if(i<0){
             return j+1;
         }
         if(j<0) return i+1;
         if(dp[i][j]!=-1) return dp[i][j];
         if(word1[i]==word2[j]) return 0+opCount(i-1,j-1,word1,word2);
         //else we have three options 
         int op1 = 1+ opCount(i,j-1,word1,word2); //insert same character at the (i+1)th position
         int op2 = 1+ opCount(i-1,j,word1,word2); //delete the ith character but we still needed to check for jth char
         int op3 = 1+ opCount(i-1,j-1,word1,word2); //replace the ith character with jth 

         return dp[i][j] =  min(op1,min(op2,op3));
     }
     int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof dp);
        return opCount(word1.length(),word2.length(),word1,word2);
    }
};
