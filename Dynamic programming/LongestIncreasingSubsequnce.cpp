class Solution {
public:
    //here pind is Previous Index and Ind is Current Index
    int lis(int ind,int pind ,vector<int>& nums,  vector<vector<int>>&dp){
        if(dp[ind][pind+1]!=-1) return dp[ind][pind+1];
        
        if(ind==nums.size()) return 0;
        int len = 0+ lis(ind+1,pind,nums,dp); //not picking the current index element that's why pind(previous index ) is still same
        if( pind==-1 ||nums[ind]>nums[pind]   ){
            return dp[ind][pind+1]=max(len,1+lis(ind+1,ind,nums,dp)); // picking the current element that's why pind(previous index ) is now current index
        }
        
        return dp[ind][pind+1]=len;  //Memoization
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>>dp(N+1,vector<int>(N+1,-1)); 
       
        return lis(0,-1,nums,dp);
    }
};
