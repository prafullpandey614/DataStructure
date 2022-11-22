class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>dp(n);
        dp[0] = 1;
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        int twomultiple,threemultiple,fivemultiple;
        for(int i=1;i<n; ++i){
            twomultiple = dp[p1]*2; //1*2
            threemultiple = dp[p2]*3; //1*3
            fivemultiple = dp[p3]*5; //1*5
            dp[i]  = min(twomultiple,min(threemultiple,fivemultiple));
            if(twomultiple==dp[i]) p1++; //increasing pointers
            if(threemultiple==dp[i]) p2++;  //not using else if for cases like 3*2 && 2*3
            if(fivemultiple==dp[i]) p3++;           
        }
        return dp[n-1];
    }
};
