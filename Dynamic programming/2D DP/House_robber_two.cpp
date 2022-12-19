class Solution {
public:
int dp[101][2];
int solve(int i,bool canrob,vector<int>& nums,int n){
    if(i>=n) return  0;
    if(dp[i][canrob]!=-1) return dp[i][canrob];
    int op1 = solve(i+1,1,nums,n);
    if(canrob){
        
        int op2 = solve(i+1,0,nums,n)+nums[i];
        return  dp[i][canrob]= max(op1,op2);
    }
    else return  dp[i][canrob] = op1 ;
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
         memset(dp,-1,sizeof dp);
            int op1 = solve(0,1,nums,n-1) ;
            memset(dp,-1,sizeof dp);
            int op2 = solve(1,1,nums,n);
            return max(op1,op2);
    }
};
