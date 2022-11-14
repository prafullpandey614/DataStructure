class Solution {
public:
    vector<int>dp;
    int rec(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 1;
        if(n==3) return 2;
        
        if(dp[n]!=-1) return dp[n];
        return dp[n] = rec(n-1)+rec(n-2)+rec(n-3);
    }
    int tribonacci(int n) {
        dp.resize(n+1,-1);
        return rec(n);
    }
};
