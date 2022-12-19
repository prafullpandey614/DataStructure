class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n  =s.size();
        int dp[n+1];
        memset(dp,0,sizeof dp);
        unordered_set<string>st;
        dp[n] = 1;
        for(string& x:wordDict) st.insert(x);
        for(int i = n-1 ; i>=0 ; --i){
            string curr="";
            for(int j = i ; j<n ; ++j){
                curr.push_back(s[j]);
                if(st.find(curr)!=st.end()){
                    if(dp[j+1]){
                        dp[i] = 1;
                    }
                    // else return 0;
                }
            }
        }
        return dp[0];
    }
};
