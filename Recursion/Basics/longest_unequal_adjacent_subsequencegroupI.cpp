class Solution {
public:
    void solve(int n,int ind,vector<string>& words, vector<int>& groups,char prev,vector<string>&ans){
        if(ind==n) return ;
        
        if(prev!=groups[ind]){
            ans.push_back(words[ind]);
            solve(n,ind+1,words,groups,groups[ind],ans);
        }
        else solve(n,ind+1,words,groups,groups[ind],ans);
        
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        vector<string>ans ;
        solve(n,0,words,groups,'#',ans);
        return ans;
    }
};
