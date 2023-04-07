class Solution {
public:
    vector<vector<int>>dpal ;
    vector<vector<int>>dp;
    bool ispal(string &s,int st,int end){
        while(st<end){
            if(s[st]!=s[end]) return 0;
            st++;
            end--;
        }
        return 1;
    }
    int solve(string &s,int st,int end){
        if(st==end or ispal(s,st,end)) return 0;
        if(dp[st][end]!=-1) return dp[st][end];
        int ans = INT_MAX;
        for(int i = st ; i<end ; ++i){
            if(ispal(s,st,i)){
                ans = min(ans,1+solve(s,i+1,end));
            }
        }
        return dp[st][end] = ans ;
    }
    int minCut(string s) {
        dpal.resize(s.size(),vector<int>(s.size(),-1));
        dp.resize(s.size(),vector<int>(s.size(),-1));

        return solve(s,0,s.size()-1);
    }
};
