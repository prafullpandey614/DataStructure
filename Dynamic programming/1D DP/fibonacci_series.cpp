class Solution {
public:
    vector<int>dp;
    int rec(int n) {
        if(n==1) return 1;
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = fib(n-1)+fib(n-2);
    }
    int fib(int n){
        dp.resize(n+1,-1);
        return rec(n);
    }
};
