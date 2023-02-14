class Solution{   
public:
int dp[100001][3];
    int rec(int i,int curr, vector<vector<int>> &colors){
        if(i>=colors.size()) return 0;
        int op1 ;
        int op2;
        if(curr!=-1)
        if(dp[i][curr]!=-1) return dp[i][curr];
        if(curr==0){
               op1  = colors[i][1] + rec(i+1,1,colors);
               op2  = colors[i][2] + rec(i+1,2,colors);
        }
        else if(curr==1){
               op1  = colors[i][0] + rec(i+1,0,colors);
               op2  = colors[i][2] + rec(i+1,2,colors);
        }
        else if(curr==2) {
               op1  = colors[i][1] + rec(i+1,1,colors);
               op2  = colors[i][0] + rec(i+1,0,colors);
        }
        // cout<<i<<" "<<min(op1,op2)<<endl;
        else{
             op1  = colors[i][1] + rec(i+1,1,colors);
             op2  = colors[i][0] + rec(i+1,0,colors);
          int   op3  = colors[i][2] + rec(i+1,2,colors);
            return dp[i][curr] = min(op1,min(op2,op3));
        }
        return dp[i][curr] = min(op1,op2);
      
    }
    int minCost(vector<vector<int>> &colors, int N) {
        
        memset(dp,-1,sizeof dp);
        return rec(0,-1,colors);
        
    }
};
