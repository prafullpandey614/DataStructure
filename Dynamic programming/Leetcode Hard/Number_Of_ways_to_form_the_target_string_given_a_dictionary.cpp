class Solution {
public:
    vector<vector<int>>freq;
    int mod = 1e9+7;
    int dp[1001][1001];
    int solve(int row,int ind,string &tar,vector<string>&words){
        if(ind==tar.size()) return 1;
        if(row==words[0].size()) return 0 ;
        if(dp[row][ind]!=-1) return dp[row][ind];
        //op1 don't consider this column i.e. skip this column
        long long count = solve(row+1,ind,tar,words)*1LL;
        //op2 if the current char in target string is more than 0 just multiply their frequncy to get all possible combinations
        count+= freq[row][tar[ind]-'a']*1LL*solve(row+1,ind+1,tar,words);
        return  dp[row][ind] = count%mod ;
    }
    int numWays(vector<string>& words, string target) {
        freq.resize(words[0].size(),vector<int>(26,0));
        memset(dp,-1,sizeof dp);
        for(int i = 0; i < words.size();++i){
            for(int j = 0 ; j < words[i].size();++j){
                int alpha_index = words[i][j]-'a';
                freq[j][alpha_index]+=1;
            }

        }
       
        return solve(0,0,target,words);
    }
};
