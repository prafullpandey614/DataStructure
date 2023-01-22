class Solution {
public:
    int trimmed[1001][1001] ;//storing trimmed value for precomputation
    int dp[1001] ;
    int dfs(int ind,vector<int>&nums,int k){
        if(ind>=nums.size()){
            return 0 ;
        }
        if(dp[ind]!=-1) return dp[ind]; 
        int output ; 
        int score = INT_MAX ;
        for(int i = ind ; i < nums.size() ; ++i){
            output = k+ trimmed[ind][i] + dfs(i+1,nums,k);
            score = min(score,output);
        }
        return dp[ind] = score ;
        
    }
    int minCost(vector<int>& nums, int k) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i < n  ; ++i){
            unordered_map<int,int>mp;
            int trim = 0 ;
            for(int j =  i ; j < n ; ++j){
                mp[nums[j]]++;
                if(mp[nums[j]]==2){
                    trim+=2;
                }
                else if(mp[nums[j]]>2){
                    trim++;
                }
                
                  trimmed[i][j] = trim;
            }
          
        }
        return dfs(0,nums,k);
    }
};
