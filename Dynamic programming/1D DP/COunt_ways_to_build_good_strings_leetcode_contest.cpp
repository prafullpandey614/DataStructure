
//problem link : https://leetcode.com/contest/biweekly-contest-91/problems/count-ways-to-build-good-strings/
class Solution {
public:
     int mod = 1e9+7;
     vector<int>dp;
    int construct(int sz,int z,int o,vector<int>&dp){
        if(sz==0) return 1;
        if(sz<0) return 0;
        if(dp[sz]!=-1) return dp[sz]%mod;
        return dp[sz] = (construct(sz-o,z,o,dp)%mod+ construct(sz-z,z,o,dp)%mod)%mod;
        
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        dp.resize(high+1,-1);
        for(int i = low ;i<=high ;++i){
            
            ans = (ans + construct(i,zero,one,dp)%mod)%mod;
        }
        return ans;
    }
};
