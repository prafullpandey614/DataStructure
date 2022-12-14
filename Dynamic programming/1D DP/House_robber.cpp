class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[nums.size()+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i =2 ;i<=nums.size(); ++i){
            // dp[i] = nums[i-1];
            int amount = 0;
            if(dp[i-1]>dp[i-2]+nums[i-1]){
                dp[i] = dp[i-1];
            }
           
            else 
             dp[i] += nums[i-1]+dp[i-2] ;
              cout<<dp[i]<<endl;
        }
        // cout<<"Ans "<<endl;
        return dp[nums.size()];
    }
};
