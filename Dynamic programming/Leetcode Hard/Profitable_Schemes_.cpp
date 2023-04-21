class Solution {
public:
    int mp ,log;
    int dp[102][102][102];
    const int mod=  1e9+7;
    int ways(int ind,vector<int>& group, vector<int>& profit,int prof,int ppl){
        // if(prof>=mp and ppl<=log) return 1;
        if(ind==group.size()){
            if(ppl>log or prof<mp){
                return 0;
            }
            return 1;
        }

        if(ppl>log) return 0; //i missed this line , plz take care of these edge cases
        if(dp[ind][prof][ppl]!=-1) return dp[ind][prof][ppl];
        int op1 =  ways(ind+1,group,profit,min(prof+profit[ind],mp),ppl+group[ind]) ;
        int op2 =  ways(ind+1,group,profit,prof,ppl);
      
        return dp[ind][prof][ppl] =  (op1%mod+op2%mod)%mod;

    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        mp = minProfit ;
        log = n ;
        memset(dp,-1,sizeof dp);
        return ways(0,group,profit,0,0)%mod;
    }
};
