class Solution {
public:
    
    int dfs(int ind,vector<int>&nums,int t,int prev){
        if(ind==nums.size()-1) return 0;
        if(ind>=nums.size()) return -1e9;
        prev = nums[ind] ;
        cout<<ind<<" ";
        int ans =  -1; 
        for(int i = ind+1; i< ind+t; ++i){
              if (i<nums.size() and nums[i]-prev>=(0-t) and nums[i]-prev<=(t) )
                {
                    return ans = max(ans,1+(dfs(i,nums,t,nums[i])));
                } 
            }
        // if(ans==-1) return 0;
        return ans ;
      
        
    }
   int maximumJumps(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] - nums[i] >= -target && nums[j] - nums[i] <= target) {
                if (dp[j] != -1) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
    }

    return dp[n - 1];
}

};
