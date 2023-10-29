class Solution {
public:
    vector<long long> dp;
    int n;
    long long solve(int ind,vector<int>&nums,int k){
        // int n = nums.size();
        if(ind>n-3){
            return 0;
        }
        if (dp[ind]!=-1){
            return dp[ind];
        }
        // op1 
        long long a = max(0,k-nums[ind]) + solve(ind+1,nums,k);
        
        // op2
        long long b = max(0,k-nums[ind+1]) + solve(ind+2,nums,k);
        
        // op3
        long long c = max(0,k-nums[ind+2]) + solve(ind+3,nums,k);
        
        return dp[ind] = min(a,min(b,c));
        
    }
    long long minIncrementOperations(vector<int>& nums, int k) {
        n = nums.size();
        dp.resize(n,-1);
        return solve(0,nums,k);
    }
};
