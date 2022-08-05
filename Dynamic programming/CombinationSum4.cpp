class Solution {
public:
    
    int recursion(vector<int>& nums, int target,vector<int>&dp){
        if(target<0) return 0 ;
        if(target==0) return 1;
        if(dp[target]!=-1) return dp[target] ;
        int ans = 0 ;
        for(int i = 0 ; i<nums.size();++i){
            ans += recursion(nums,target-nums[i],dp);
        }
        return dp[target]=ans ;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1);
         for(int i = 0; i <dp.size();++i){
             dp[i] = -1;
         }
        return recursion(nums,target,dp);
        
    }
};
