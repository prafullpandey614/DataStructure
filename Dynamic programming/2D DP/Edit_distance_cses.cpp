int dp[5001][5001];
int solve(int i,int j,string &s1,string &s2){
   if(i==s1.length() || j==s2.length()){
       return max(s1.length()-i,s2.length()-j);
   }
   if(dp[i][j]!=-1){
       return dp[i][j];
   }
   else{
       if(s1[i]==s2[j]){
           return dp[i][j]=solve(i+1,j+1,s1,s2);
       }
       int op1 = 1+ solve(i+1,j,s1,s2);//remove
       int op2 = 1+solve(i,j+1,s1,s2);//add
       int op3 = 1+ solve(i+1,j+1,s1,s2); //replace
       return dp[i][j]= min(op1,min(op2,op3));
   }
}
