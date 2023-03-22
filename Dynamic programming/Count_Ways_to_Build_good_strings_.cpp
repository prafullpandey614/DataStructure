class Solution {
public:
     int mod = 1e9+7;
     int l , h,z,o ;
     int dp[100001];
    int solve(int len){
        if(len>h){
            return 0 ;
        }
        if(dp[len]!=-1) return dp[len];
        if(len>=l and len<=h)
        return dp[len]= (1+ solve(len+o)+solve(len+z))%mod;
        return dp[len] = (solve(len+o)+solve(len+z))%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        l = low , h = high ;
        z = zero,o = one ;
        memset(dp,-1,sizeof dp);
        return solve(0)%mod;
      
    }
};
