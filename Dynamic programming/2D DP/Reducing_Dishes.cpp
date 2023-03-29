class Solution {
public:
    int ans= 0 ;
    int dp[501][501];
    int  solve(int ind,int tin,vector<int>& s){
        if(ind==s.size()){
            
            return 0;
        }
        if(dp[ind][tin]!=-1) return dp[ind][tin];
        //op1
        int k = s[ind]*tin + solve(ind+1,tin+1,s);
        //op2
        int l = solve(ind+1,tin,s);
        // cout<<k<<" "<<l<<endl;
        return  dp[ind][tin] = max(k,l);
    }
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        memset(dp,-1,sizeof  dp);
        
        return solve(0,1,s);
    }
};
