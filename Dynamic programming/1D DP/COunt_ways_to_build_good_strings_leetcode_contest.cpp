
//problem link : https://leetcode.com/contest/biweekly-contest-91/problems/count-ways-to-build-good-strings/
class Solution {
public:
     int mod = 1e9+7;
     vector<int>dp;
     //this function will give count of  all the possible strings having length only equal to sz 
    int construct(int sz,int z,int o,vector<int>&dp){
        if(sz==0) return 1; //Base Case :  If Size of string becomes exactly equal to sz , then sz will become 0 hence  return 1
        if(sz<0) return 0; // other wise it will go in negative so return zero
        if(dp[sz]!=-1) return dp[sz]%mod; //memoization
        return dp[sz] = (construct(sz-o,z,o,dp)%mod+ construct(sz-z,z,o,dp)%mod)%mod; // checing for both cases for one and than for zeroes
        
        
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        dp.resize(high+1,-1);
        for(int i = low ;i<=high ;++i){
            
            ans = (ans + construct(i,zero,one,dp)%mod)%mod;  // we are finding the all possiblities of length i from low to high
        }
        return ans;
    }
};
