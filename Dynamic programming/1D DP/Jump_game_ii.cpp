class Solution {
public:
    int jump(vector<int>& nums) {
        int dp[nums.size()]; // dp[i] indicates minimum number of steps required to reach 1 from i
        memset(dp,0,sizeof(dp));
        int n= nums.size();
        dp[n-1] = 0;
        for(int i =  n-2;  i >=0 ; --i){
            
            int cost = 1e7 ;
            dp[i] = 1;
            for(int x = 1 ; x<=nums[i] ; ++x){
                if(x+i>=n) break ;
                else cost = min(cost,dp[i+x]);
            }
            dp[i] += cost ;
            
            
        }
        return dp[0] ;
    }
};
