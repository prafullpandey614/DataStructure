class Solution {
public:
    int n,m;
    vector<vector<int>>dp;
    int solve(int left,int i,vector<int>&nums,vector<int>&mul){
        if(i==m) return 0;
        if(dp[left][i]!=INT_MIN) return dp[left][i];
        int result;
        
        result =  nums[left]*mul[i] +  solve(left+1,i+1,nums,mul);
        result = max(result , nums[n-(i-left)-1]*mul[i]+solve(left,i+1,nums,mul));
        return dp[left][i]=result;
    }
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        n = nums.size();
        m = mul.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        
        return solve(0,0,nums,mul);
        
    }
};
