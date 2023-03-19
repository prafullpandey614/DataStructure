class Solution {
public:
    // vector<string>ans;
    int count = 0; 
    vector<char>vow = {'a','e','i','o','u'};
    int dp[51];
    void solve(int ind, int n, string &curr,int val){
        if(ind==n){
           
            count++;
            return ;
        }
       
        for(int i = val ; i <5 ; ++i){
            curr.push_back(vow[i]) ;
            solve(ind+1,n,curr,i);
            curr.pop_back();
        }
    }
    int countVowelStrings(int n) {
        string curr="";
        memset(dp,-1,sizeof dp);
        
        solve(0,n,curr,0);
        return count;
    }
};
